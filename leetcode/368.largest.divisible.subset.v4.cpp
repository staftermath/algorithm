//
// Created by gwengww on 6/8/18.
// beat 91.16%
// no private function, don't need to pass out value

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.empty()) return {};
        vector<int> dp(nums.size(), 1);
        vector<int> pre(nums.size(), -1);
        int maximum = 1;
        int selected = 0;
        for (int i=1; i<nums.size(); i++) {
            for (int k = i-1; k>=0; k--) {
                if (nums[i] % nums[k] == 0 && dp[k] >= dp[i]) {
                    pre[i] = k;
                    dp[i] = dp[k]+1;
                }
            }
            if (dp[i] > maximum) {
                selected = i;
                maximum = dp[i];
            }
        }
        vector<int> result;
        while (selected != -1) {
            result.push_back(nums[selected]);
            selected = pre[selected];
        }
        return result;

    }
};