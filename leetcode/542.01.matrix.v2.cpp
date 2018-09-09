//
// Created by gwengww on 9/9/18.
// 160ms 49.78%
// time O(n*n) constant is 4
// space O(n*n)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (height == 0) return {};
        int width = matrix[0].size();
        vector<vector<int>> dp(height, vector<int>(width, INT_MAX-1));
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    // only look back
                    if (i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                    if (j>0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        for (int i=height-1; i>=0; i--) {
            for (int j=width-1; j>=0; j--) {
                if (matrix[i][j] !=0) {
                    // 0's have been filled. only look back
                    if (i+1<height) dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                    if (j+1<width) dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                }
            }
        }
        return dp;
    }
};