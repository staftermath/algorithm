//
// Created by gwengww on 8/4/18.
// 16 ms 25.93%
// time O(m*n)
// space O(m*n)

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if (m <=1) return;
        int n=board[0].size();
        if (n <=1) return;
        vector<int> parents(m*n);
        // for (int i=0; i<m*n; i++) {
        //     parents[i] = i;
        // }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int f = i*n+j;
                // cout << i << "," << j << endl;
                if (board[i][j] == 'O') {
                    parents[f] = f;
                    if (i>0 && board[i-1][j] == 'O' && findParent(parents, f-n) != f) parents[findParent(parents, f-n)] = f;
                    // if (i<m-1 && board[i+1][j] == 'O' && findParent(parents, f+n) != f) parents[findParent(parents, f+n)] = f;
                    if (j>0 && board[i][j-1] == 'O' && findParent(parents, f-1) != f) parents[findParent(parents, f-1)] = f;
                    // if (j<n-1 && board[i][j+1] == 'O' && findParent(parents, f+1) != f) parents[findParent(parents, f+1)] = f;

                }
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'O') findParent(parents, i*n+j);
            }
        }
        unordered_set<int> side_island;
        for (int i=0; i<m; i++) {
            if (board[i][0] == 'O') side_island.insert(findParent(parents, i*n));
            if (board[i][n-1] == 'O') side_island.insert(findParent(parents, i*n+n-1));
        }
        for (int j=0; j<n; j++) {
            if (board[0][j] == 'O') side_island.insert(findParent(parents, j));
            if (board[m-1][j] == 'O') side_island.insert(findParent(parents, m*n-n+j));
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'O' && side_island.find(parents[i*n+j]) == side_island.end()) board[i][j] = 'X';
            }
        }
    }

    int findParent(vector<int>& parents, int x) {
        // cout << "parents of " << x << " is " << parents[x] << endl;
        if (parents[x] == x) return x;
        parents[x] = findParent(parents, parents[x]);
        return parents[x];
    }
};