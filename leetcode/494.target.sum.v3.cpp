//
// Created by gwengww on 6/10/18.
// 15ms 78.14%
// time O(N*SUM)
// space O(N*SUM)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ( sum < s || sum < -s || (sum-s)&1) return 0;
        int target = (sum-s)/2;
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, 0));
        dp[0][0] = 1;
        dp[0][nums[0]]++;
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<=sum; j++) {
                if (j<nums[i]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[nums.size()-1][target];
    }
};