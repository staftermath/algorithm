//
// Created by gwengww on 7/23/18.
// time O(area)
// space O(area)

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int size = rectangles.size();
        if (size == 0) return false;
        int top = INT_MAX, left = INT_MAX, bottom = INT_MIN, right = INT_MIN;
        for (int i=0; i<size; i++) {
            if (rectangles[i][0] < top) top = rectangles[i][0];
            if (rectangles[i][1] < left) left = rectangles[i][1];
            if (rectangles[i][2] > bottom) bottom = rectangles[i][2];
            if (rectangles[i][3] > right) right = rectangles[i][3];
        }
        vector<vector<int>> slots(bottom-top, vector<int>(right-left));
        int total_area = 0;
        for (int i=0; i<size; i++) {
            for (int m=rectangles[i][0]; m<rectangles[i][2]; m++) {
                for (int n=rectangles[i][1]; n<rectangles[i][3]; n++) {
                    if (slots[m-top][n-left] == 1) return false;
                    slots[m-top][n-left] = 1;
                    total_area+=1;
                }
            }
        }
        return total_area == (bottom-top)*(right-left);

    }
};