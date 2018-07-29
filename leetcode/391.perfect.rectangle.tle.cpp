//
// Created by gwengww on 7/23/18.
//

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int size = rectangles.size();
        if (size == 0) return false;
        sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b){return (a[1] == b[1] && a[0] < b[0]) || a[1] < b[1];});
        int top = INT_MAX, left = INT_MAX, bottom = INT_MIN, right = INT_MIN;
        int p_top, p_left, p_bottom, p_right;
        int square_area = 0;
        for (int i=0; i<size; i++) {
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
            square_area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        }
        // cout << top << "," << left << "||" << bottom << "," << right << endl;
        // cout << p_top << "," << p_left << "||" << p_bottom << "," << p_right << endl;
        int expected_area = (bottom-top)*(right-left);
        if (square_area != expected_area) return false;
        if (p_top != p_left || p_bottom != p_right) return false;
        int last;
        int current_row = top;
        while (current_row < bottom) {
            last = -1;
            for (int i=0; i<size; i++) {
                if (rectangles[i][0] <= current_row && rectangles[i][2] > current_row) {
                    if (last == -1 || rectangles[i][1] == last) {
                        last = rectangles[i][3];
                        rectangles[i][0]++;
                    }
                    else return false;
                }
            }
            if (last != right) return false;
            current_row++;
        }
        return true;

    }
};