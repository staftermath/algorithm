//
// Created by gwengww on 4/30/18.
// use reference of the word and starting point instead of a copy of the word
// beat 96.79%

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

                if (helper(i, j, board, word, 0)) return true;
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
    bool helper(int x, int y, vector<vector<char>>& board, string& word, int start) {
        bool result = false;
        if (!isValid(x, y) || start >= word.size()) return false;
        if (board[x][y] != word[start]) return false;
        if (start == word.size()-1) return true;
        board[x][y] = '\0';
        result = helper(x-1, y, board, word, start+1) ||
                 helper(x+1, y, board, word, start+1) ||
                 helper(x, y-1, board, word, start+1) ||
                 helper(x, y+1, board, word, start+1);
        if (result) return true;
        board[x][y] = word[start];
        return false;

    }
};