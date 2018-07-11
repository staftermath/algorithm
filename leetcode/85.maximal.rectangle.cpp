//
// Created by gwengww on 7/10/18.
// 12ms 98.03%
// time O(n^2)
// space O(n^2)
// see 84.largest.rectangle.in.histogram

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int height = matrix.size(), width = matrix[0].size();
        vector<vector<int>> histogram(height, vector<int>(width));
        getHistogram(histogram, matrix);
        vector<int> left(width), right(width);
        int max_area = 0;
        for (int i=0; i<height; i++) {
            max_area = max(max_area, maxHistogram(left, right, histogram, i));
        }
        return max_area;
    }
    void getHistogram(vector<vector<int>>& histogram, vector<vector<char>>& matrix) {
        int height = matrix.size(), width = matrix[0].size();
        int current_bar;
        for (int j=0; j<width; j++) {
            current_bar = 0;
            for (int i=0; i<height; i++) {
                if (matrix[i][j] == '1') {
                    current_bar++;
                } else {
                    current_bar = 0;
                }
                histogram[i][j] = current_bar;
            }
        }
    }
    int maxHistogram(vector<int>& left, vector<int>& right, vector<vector<int>>& histogram, int row) {
        int width = left.size();
        left[0] = -1;
        right[width-1] = width;
        int p, max_area=0;
        for (int i=1; i<width; i++) {
            p = i-1;
            while (p>=0 && histogram[row][p] >= histogram[row][i]) {
                p = left[p];
            }
            left[i] = p;
        }
        for (int i=width-2; i>=0; i--) {
            p = i+1;
            while (p<width && histogram[row][p] >= histogram[row][i]) {
                p = right[p];
            }
            right[i] = p;
        }
        for (int i=0; i<width; i++) {
            max_area = max(max_area, (right[i]-left[i]-1)*histogram[row][i]);
        }
        return max_area;


    }
};