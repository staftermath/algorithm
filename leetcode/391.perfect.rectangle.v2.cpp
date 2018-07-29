//
// Created by gwengww on 7/24/18.
// 60ms 77.91%
// time O(n)
// space O(n)
// used bitmask instead of struct

class Solution {
public:
    inline bool add_corners(unordered_map<int, unordered_map<int, int>>& corners, int x, int y, int pos) {
        int& m = corners[x][y];
        if (m&pos) return false;
        m |= pos;
        return true;
    }

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int size = rectangles.size();
        if (size == 0) return false;
        int top = INT_MAX, left = INT_MAX, bottom = INT_MIN, right = INT_MIN;
        int this_top, this_left, this_bottom, this_right;
        int p_top, p_left, p_bottom, p_right;
        unordered_map<int, unordered_map<int, int>> corners;
        set<pair<int, int>> main_corners;

        for (int i=0; i<size; i++) {
            this_top = rectangles[i][0];
            this_left = rectangles[i][1];
            this_bottom = rectangles[i][2];
            this_right = rectangles[i][3];
            if (!add_corners(corners, this_top, this_left, 1) ||
                !add_corners(corners, this_top, this_right, 2) ||
                !add_corners(corners, this_bottom, this_left, 4) ||
                !add_corners(corners, this_bottom, this_right, 8)) return false;
            if (this_top <= top) {
                top = this_top;
            }
            if (this_left <= left) {
                left = this_left;
            }
            if (this_top <= top && this_left <= left) {
                p_top = i;
                p_left = i;
            }
            if (this_bottom >= bottom) {
                bottom = this_bottom;
            }
            if (this_right >= right) {
                right = this_right;
            }
            if (this_bottom >= bottom && this_right >= right) {
                p_bottom = i;
                p_right = i;
            }
        }
        if (p_top != p_left || p_bottom != p_right) return false;
        main_corners.insert(make_pair(top, left));
        main_corners.insert(make_pair(top, right));
        main_corners.insert(make_pair(bottom, left));
        main_corners.insert(make_pair(bottom, right));
        for (auto x_map: corners) {
            for (auto y_map: x_map.second) {
                if (!valid_corner(x_map.first, y_map.first, y_map.second, main_corners)) return false;
            }
        }
        return true;

    }

    bool valid_corner(int x, int y, int pos, set<pair<int, int>>& main_corners) {
        if (pos == 1 || pos == 2 || pos == 4 || pos == 8) {
            if (main_corners.find(make_pair(x,y)) == main_corners.end()) return false;
            return true;
        }
        if (pos == 3 || pos == 10 || pos == 12 || pos == 5 || pos == 15) return true;
        return false;
    }
};