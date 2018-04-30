//
// Created by gwengww on 4/30/18.
// change original board instead of search cached path (increase to 15.10%).
// do not initiate candidate vector every time (increase to 63.94%)
// no need to keep a copy of first char, can just directly use first char in word. (doesn't change much)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        x_length = board.size();
        if (x_length == 0) return false;
        y_length = board[0].size();
        if (y_length == 0) return false;
        for (int i=0; i<x_length; i++) {
            for (int j=0; j<y_length; j++) {

                if (helper(i, j, board, word)) return true;
            }
        }
        return false;
    }
private:
    int x_length, y_length;

    bool isValid(int x, int y) {
        if (x>=0 && y >=0 && x <x_length && y<y_length) return true;
        return false;
    }
    bool helper(int x, int y, vector<vector<char>>& board, string word) {
        bool result = false;
        if (!isValid(x, y)) return false;
        if (board[x][y] != word[0]) return false;
        if (word.size() == 1) return true;
        char temp = board[x][y]; // no need to keep a copy of the char, can use word[0]
        board[x][y] = '\0';
        result = helper(x-1, y, board, word.substr(1)) ||
                 helper(x+1, y, board, word.substr(1)) ||
                 helper(x, y-1, board, word.substr(1)) ||
                 helper(x, y+1, board, word.substr(1));
        if (result) return true;
        board[x][y] = temp;
        return false;

    }
};