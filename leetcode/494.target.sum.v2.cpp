//
// Created by gwengww on 5/30/18.
// beat 59.54%
// skip in the middle process if impossible to get a sum from rest of vectors.
// sorting helps

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        if (nums.size() == 1) {
            if (nums[0] == S) count++;
            if (nums[0] == -S) count++;
            return count;
        }
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){return a>b;});
        vector<int> maximal(nums.size(), 0);
        vector<int> minimal(nums.size(), 0);
        maximal[nums.size()-1] = nums[nums.size()-1];
        minimal[nums.size()-1] = -nums[nums.size()-1];
        for (int i=nums.size()-2; i>=0; i--) {
            maximal[i] = maximal[i+1]+nums[i];
            minimal[i] = minimal[i+1]-nums[i];
        }
        findTargetSumWays(nums, 0, S, count, maximal, minimal);
        return count;
    }

    void findTargetSumWays(vector<int>& nums, int start, int S, int& count, const vector<int>& maximal, const vector<int>& minimal) {
        if (start == nums.size()-1) {
            if (nums[start] == S) count++;
            if (nums[start] == -S) count++;
            return;
        }
        if (S > -minimal[start] || S < -maximal[start]) return;
        findTargetSumWays(nums, start+1, S+nums[start], count, maximal, minimal);
        findTargetSumWays(nums, start+1, S-nums[start], count, maximal, minimal);
        return;
    }
};