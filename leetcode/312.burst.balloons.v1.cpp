//
// Created by gwengww on 6/17/18.
// 21ms 18.72%

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, -1));
        return calculateDP(dp, 0, size-1, nums);
    }

    int calculateDP(vector<vector<int>>& dp, int i, int j, vector<int>& nums) {
        if (i>j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int left = (i>0)? nums[i-1]: 1;
        int right = (j<nums.size()-1)? nums[j+1]: 1;
        for (int k=i; k<=j; k++) {
            dp[i][j] = max(dp[i][j], calculateDP(dp, i, k-1, nums) + left*nums[k]*right + calculateDP(dp, k+1, j, nums));
        }
        return dp[i][j];
    }
};