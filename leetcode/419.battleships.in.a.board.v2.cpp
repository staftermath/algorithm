//
// Created by gwengww on 6/28/18.
// time O(N^2)
// space O(1)

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int total = 0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == 'X' && (i>0 && board[i-1][j] != 'X' || i==0) && (j>0 && board[i][j-1] != 'X' || j==0)) total++;
            }
        }
        return total;
    }
};