//
// Created by gwengww on 5/30/18.
// beat 36.01%
// O(2^N)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        int count = 0;
        findTargetSumWays(nums, 0, S, count);
        return count;
    }

    void findTargetSumWays(vector<int>& nums, int start, int S, int& count) {
        if (start == nums.size()-1) {
            if (S == 0 && nums[start] == 0) count += 2;
            else if (nums[start] == S || nums[start] == -S) count++;
            return;
        }
        findTargetSumWays(nums, start+1, S+nums[start], count);
        findTargetSumWays(nums, start+1, S-nums[start], count);
        return;
    }
};