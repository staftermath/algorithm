//
// Created by gwengww on 6/17/18.
// 9ms 98.61%
// remove recursion.
// start from short gap (gap=0, 1, 2, ... )

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for (int l=0; l<nums.size(); l++) {
            for (int start=1; start+l<=nums.size()-2; start++) {
                int end = start+l;
                int prod = nums[start-1]*nums[end+1];
                for (int k=start; k<=end; k++) {
                    dp[start][end] = max(dp[start][end], dp[start][k-1] + prod*nums[k] + dp[k+1][end]);
                }
            }
        }
        return dp[1][nums.size()-2];
    }
};