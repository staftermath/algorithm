//
// Created by gwengww on 7/24/18.
// 96ms 22.67%
// time O(n)
// space O(n)

class Solution {
public:
    struct Rec {
        bool top_left=false;
        bool top_right=false;
        bool bottom_left=false;
        bool bottom_right=false;
        int count=0;
    };

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int size = rectangles.size();
        if (size == 0) return false;
        int top = INT_MAX, left = INT_MAX, bottom = INT_MIN, right = INT_MIN;
        int p_top, p_left, p_bottom, p_right;
        map<pair<int, int>, Rec> corners;
        set<pair<int, int>> main_corners;
        for (int i=0; i<size; i++) {
            if (!add_corners(corners, rectangles[i])) return false;
            if (rectangles[i][0] <= top) {
                top = rectangles[i][0];
            }
            if (rectangles[i][1] <= left) {
                left = rectangles[i][1];
            }
            if (rectangles[i][0] <= top && rectangles[i][1] <= left) {
                p_top = i;
                p_left = i;
            }
            if (rectangles[i][2] >= bottom) {
                bottom = rectangles[i][2];
            }
            if (rectangles[i][3] >= right) {
                right = rectangles[i][3];
            }
            if (rectangles[i][2] >= bottom && rectangles[i][3] >= right) {
                p_bottom = i;
                p_right = i;
            }
        }
        if (p_top != p_left || p_bottom != p_right) return false;
        main_corners.insert(make_pair(top, left));
        main_corners.insert(make_pair(top, right));
        main_corners.insert(make_pair(bottom, left));
        main_corners.insert(make_pair(bottom, right));
        // cout << top << "," << left << "||" << bottom << "," << right << endl;
        // for (auto c: main_corners) {
        //     cout << c.first << "," << c.second << endl;
        // }
        // cout << "algorithm" << endl;
        // count corner
        for (auto corner: corners) {
            // cout << corner.first.first << ","<< corner.first.second << ": " << corner.second << endl;
            if (!valid_corner(corner, main_corners)) return false;
        }
        return true;

    }

    bool add_corners(map<pair<int, int>, Rec>& corners, vector<int>& rectangle) {
        pair<int, int> corner;
        corner = make_pair(rectangle[0],rectangle[1]);
        if (corners.find(corner) != corners.end() && corners[corner].top_left) return false;
        else {
            corners[corner].top_left = true;
            corners[corner].count++;
        }
        corner = make_pair(rectangle[0],rectangle[3]);
        if (corners.find(corner) != corners.end() && corners[corner].top_right) return false;
        else {
            corners[corner].top_right = true;
            corners[corner].count++;
        }
        corner = make_pair(rectangle[2],rectangle[1]);
        if (corners.find(corner) != corners.end() && corners[corner].bottom_left) return false;
        else {
            corners[corner].bottom_left = true;
            corners[corner].count++;
        }
        corner = make_pair(rectangle[2],rectangle[3]);
        if (corners.find(corner) != corners.end() && corners[corner].bottom_right) return false;
        else {
            corners[corner].bottom_right = true;
            corners[corner].count++;
        }
        return true;
    }

    bool valid_corner(const pair<pair<int, int>, Rec> & corner, set<pair<int, int>>& main_corners) {
        if (corner.second.count == 1) {
            if (main_corners.find(corner.first) == main_corners.end()) return false;
        }
        if (corner.second.count == 2) {
            if ((corner.second.top_left && corner.second.bottom_right) || (corner.second.top_right && corner.second.bottom_left)) return false;
        }
        if (corner.second.count == 3) return false;
        return true;

    }
};