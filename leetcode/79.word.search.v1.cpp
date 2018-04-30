//
// Created by gwengww on 4/30/18.
// beat 9.29%

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
                vector<vector<int>> path;
                if (helper(i, j, board, word, path)) return true;
            }
        }
        return false;
    }
private:
    int x_length, y_length;
    bool searched(int x, int y, const vector<vector<int>>& path) {
        for (auto v: path) {
            if (x==v[0] && y==v[1]) return true;
        }
        return false;
    }

    bool isValid(int x, int y, vector<vector<int>>& path) {
        if (x>=0 && y >=0 && x <x_length && y<y_length && !searched(x, y, path)) return true;
        return false;
    }
    bool helper(int x, int y, vector<vector<char>>& board, string word, vector<vector<int>> path) {
        bool result = false;
        if (board[x][y] != word[0]) return false;
        if (word.size() == 1) return true;
        path.push_back({x, y});
        vector<vector<int>> next = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
        for (auto v: next) {
            result = isValid(v[0], v[1], path)? helper(v[0], v[1], board, word.substr(1), path): false;
            if (result) return true;
        }
        return false;
    }
};