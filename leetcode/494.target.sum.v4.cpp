//
// Created by gwengww on 6/10/18.
// 7ms 93.56%
// same idea as v3
// time O(n*sum)
// space O(sum)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ( sum < s || sum < -s || (sum-s)&1) return 0;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for (auto& n: nums) {
            for (int i=sum; i>=n; i--) {
                dp[i] += dp[i-n];
            }
        }
        return dp[(sum-s)/2];
    }
};