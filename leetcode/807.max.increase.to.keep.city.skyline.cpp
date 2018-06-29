//
// Created by gwengww on 6/22/18.
// 10ms 99.27%

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size();
        vector<int> left_to_right(height);
        vector<int> top_to_bottom(width);
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                top_to_bottom[j] = max(top_to_bottom[j], grid[i][j]);
                left_to_right[i] = max(left_to_right[i], grid[i][j]);
            }
        }
        int increase = 0;
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                increase += min(top_to_bottom[j],left_to_right[i])-grid[i][j];
            }
        }
        return increase;
    }
};