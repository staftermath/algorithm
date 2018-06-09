//
// Created by gwengww on 6/7/18.
// beat 16.02%

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.empty()) return {};
        vector<vector<int>> dp(nums.size());
        int maximum = 0;
        int selected = 0;
        dp[0] = {nums[0]};
        for (int i=1; i<nums.size(); i++) {
            int size = fill_dp(i, dp, nums);
            if (size > maximum) {maximum = size; selected = i;}
        }
        return dp[selected];

    }
private:
    int fill_dp(int pos, vector<vector<int>>& dp, vector<int>& nums) {
        int maximum = 0;
        int selected = -1;
        for (int i=pos-1; i>=0; i--) {
            if (nums[pos] % dp[i].back() == 0 && dp[i].size() > maximum) {
                selected = i;
                maximum = dp[i].size();
            }
        }
        if (selected != -1) {
            vector<int> result(dp[selected]);
            result.push_back(nums[pos]);
            dp[pos] = result;
        } else {
            dp[pos] = {nums[pos]};
        }
        return dp[pos].size();
    }
};