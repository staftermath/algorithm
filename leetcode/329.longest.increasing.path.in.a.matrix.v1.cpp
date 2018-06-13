//
// Created by gwengww on 6/12/18.
// 61ms 32.74%
// change addPath() to return length of path ending in given pos will
// improve result to 57ms and 35.89%
// fill in valid instead of passing out valid will improve result to 54ms and 37.40%
// don't use finished as flag, use LIP[x][y] > 0 instead , reduce space. time won't change

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> finished(m, vector<int>(n));
        vector<vector<int>> LIP(m, vector<int>(n));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                addPath(matrix, i, j, finished, LIP, m, n);
            }
        }
        int current_max_length = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (LIP[i][j] > current_max_length) {
                    current_max_length = LIP[i][j];
                }
            }
        }
        return current_max_length;
    }

    void addPath(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& finished, vector<vector<int>>& LIP, const int m, const int n) {
        if (finished[x][y]) return;
        auto valid = get_valid_neighbor(matrix, x, y, finished, m, n);
        for (auto& p: valid) {
            addPath(matrix, p.first, p.second, finished, LIP, m, n);
        }

        int max_length = 1;
        for (int i=0; i<valid.size(); i++) {
            if (LIP[valid[i].first][valid[i].second] >= max_length) {
                max_length = LIP[valid[i].first][valid[i].second]+1;
            }
        }
        LIP[x][y] = max_length;
        finished[x][y] = 1;
        return;
    }

    vector<pair<int, int>> get_valid_neighbor(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& finished, const int m, const int n) {
        vector<pair<int, int>> result;
        if (y+1<n && matrix[x][y+1] < matrix[x][y]) result.emplace_back(x, y+1);
        if (y-1>=0 && matrix[x][y-1] < matrix[x][y]) result.emplace_back(x, y-1);
        if (x+1<m && matrix[x+1][y] < matrix[x][y]) result.emplace_back(x+1, y);
        if (x-1>=0 && matrix[x-1][y] < matrix[x][y]) result.emplace_back(x-1, y);
        sort(result.begin(), result.end(), [&matrix](const pair<int, int>& a, const pair<int, int>& b) {
            return matrix[a.first][a.second] < matrix[b.first][b.second];
        });
        return result;
    }
};