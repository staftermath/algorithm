//
// Created by gwengww on 7/10/18.
// 8ms 98.84%
// time O(n)
// space O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size(), max_area = 0;
        if (size == 0) return 0;
        vector<int> left(size), right(size);
        left[0] = -1;
        right[size-1] = size;
        for (int i=1; i< size; i++) {
            int p=i-1;
            while (p>=0 && heights[p] >= heights[i]) {
                p = left[p];
            }
            left[i] = p;
        }
        for (int i=size-2; i>=0; i--) {
            int p=i+1;
            while (p<size && heights[p] >= heights[i]) {
                p = right[p];
            }
            right[i] = p;
        }

        for (int i=0; i < heights.size(); i++) {
            // cout << left[i] << ", " << right[i] << endl;
            max_area = max(max_area, (right[i]-left[i]-1)*heights[i]);
        }
        return max_area;
    }
};