//
// Created by gwengww on 9/9/18.
// 204ms 30.95%
// time O(n*n) constant is 8
// space O(n*n)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (height == 0) return {};
        int width = matrix[0].size();
        vector<vector<int>> dp(height, vector<int>(width, INT_MAX));
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                minimalNeighbor(matrix, dp, i, j, height, width);
            }
        }
        for (int i=height-1; i>=0; i--) {
            for (int j=width-1; j>=0; j--) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                minimalNeighbor(matrix, dp, i, j, height, width);
            }
        }
        return dp;

    }
    void minimalNeighbor(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int height, int width) {
        if (i>0) {
            // look up
            if (matrix[i-1][j] == 0) {
                dp[i][j] = 1;
                return;
            }
            if (dp[i-1][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
        }
        if (j>0) {
            // look left
            if (matrix[i][j-1] == 0) {
                dp[i][j] = 1;
                return;
            }
            if (dp[i][j-1] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
        }
        if (i+1<height) {
            // look down
            if (matrix[i+1][j] == 0) {
                dp[i][j] = 1;
                return;
            }
            if (dp[i+1][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
        }
        if (j+1<width) {
            // look down
            if (matrix[i][j+1] == 0) {
                dp[i][j] = 1;
                return;
            }
            if (dp[i][j+1] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
        }
    }
};