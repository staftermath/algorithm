//
// Created by gwengww on 6/27/18.
// 8ms 90.82%
// time O(N^2)
// space O(1)
// modifying board

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int total = 0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == 'X') {
                    total++;
                    findBattleships(board, i, j);
                }
            }
        }
        return total;
    }

    void findBattleships(vector<vector<char>>& board, int i, int j) {
        if (j+1 < board[0].size() && board[i][j+1] == 'X') {
            int k = j;
            while (k < board[0].size() && board[i][k] == 'X') board[i][k++] = '.';
            return;
        }
        if (i+1 < board.size() && board[i+1][j] == 'X') {
            int k = i;
            while (k < board.size() && board[k][j] == 'X') board[k++][j] = '.';
            return;
        }
        board[i][j] = '.';
    }
};