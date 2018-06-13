//
// Created by gwengww on 6/12/18.
// 32ms 95.34%
// remove valid completely and pass value of current block to next step
// 

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> LIP(m, vector<int>(n));
        int current_max_length = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                current_max_length = max(current_max_length, addPath(matrix, i, j, LIP, m, n, INT_MAX));
            }
        }
        return current_max_length;
    }

    int addPath(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& LIP, const int m, const int n, const int val) {
        if (y>=n || y<0 || x>=m || x<0 || matrix[x][y] >= val) return 0;
        if (LIP[x][y] > 0) return LIP[x][y];
        // vector<pair<int, int>> valid;
        // get_valid_neighbor(matrix, x, y, m, n, valid);
        int max_length = 1;
        max_length = max(max_length, addPath(matrix, x+1, y, LIP, m, n, matrix[x][y])+1);
        max_length = max(max_length, addPath(matrix, x-1, y, LIP, m, n, matrix[x][y])+1);
        max_length = max(max_length, addPath(matrix, x, y+1, LIP, m, n, matrix[x][y])+1);
        max_length = max(max_length, addPath(matrix, x, y-1, LIP, m, n, matrix[x][y])+1);
        LIP[x][y] = max_length;
        return max_length;
    }

};