//
// Created by gwengww on 5/30/18.
// beat 74.05%
// convert to:
// sum of a subset is half of total -> if total is not even return false;
// watch out for integer overflow when calculating dp:
// don't use dp[i] += dp[i-n]

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unsigned long total = accumulate(nums.begin(), nums.end(), 0);
        if (total & 1 == 1) return false;
        unsigned long half = total >> 1;
        vector<int> dp(half+1, 0);
        dp[0] = 1;
        for (auto& n: nums) {
            for (unsigned long i=half; i>=n; i--) {
                dp[i] = dp[i] || dp[i-n];
            }
        }
        return dp[half] > 0;
    }
};