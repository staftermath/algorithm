//
// Created by gwengww on 9/23/18.
// 0ms 100%
// time O(n*m)
// space O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (height == 0) return {};
        int width = matrix[0].size();
        int count = height*width;
        int move_index = 0;
        pair<int, int> pos = {0, 0}, next_pos, move;
        vector<int> result(count, 0);
        vector<pair<int, int>> moves = {make_pair(0,1), make_pair(1,0), make_pair(0,-1), make_pair(-1,0)};
        move = moves[move_index];
        result[0] = matrix[0][0];
        int max_height = height, min_height = 0, max_width = width, min_width = 0;
        for (int i=1; i<count; i++) {
            // cout << "at " << pos.first << "," << pos.second << endl;
            next_pos.first = pos.first+move.first;
            next_pos.second = pos.second+move.second;
            if (next_pos.first >= max_height || next_pos.first < min_height || next_pos.second >= max_width || next_pos.second < min_width) {
                if (move_index == 0) min_height++;
                else if (move_index == 1) max_width--;
                else if (move_index == 2) max_height--;
                else min_width++;
                move_index = ++move_index%4;
                move = moves[move_index];
                next_pos.first = pos.first+move.first;
                next_pos.second = pos.second+move.second;
            }
            result[i] = matrix[next_pos.first][next_pos.second];
            pos = next_pos;
        }
        return result;
    }
};