//
// Created by gwengww on 6/8/18.
// beat 40.61%
// no vector construction when building states


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
            int length = fill_dp(i, dp, nums, pre);
            if (length > maximum) {
                selected = i;
                maximum = length;
            }
        }
        vector<int> result;
        while (selected != -1) {
            result.push_back(nums[selected]);
            selected = pre[selected];
        }
        return result;

    }
private:
    int fill_dp(int pos, vector<int>& dp, vector<int>& nums, vector<int>& pre) {
        for (int i = pos-1; i>=0; i--) {
            if (nums[pos] % nums[i] == 0 && dp[i] >= dp[pos]) {
                pre[pos] = i;
                dp[pos] = dp[i]+1;
            }
        }
        return dp[pos];
    }
};