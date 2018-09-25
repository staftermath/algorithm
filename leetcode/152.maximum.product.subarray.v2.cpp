//
// Created by gwengww on 9/24/18.
// 4ms 98.57%
// time O(n)
// space O(n)
// beautiful and simple
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        vector<int> maxs(size, nums[0]), mins(size, nums[0]);
        int result = nums[0];
        for (int i=1; i<size; i++) {
            maxs[i] = max(max(maxs[i-1]*nums[i], nums[i]), mins[i-1]*nums[i]);
            mins[i] = min(min(maxs[i-1]*nums[i], nums[i]), mins[i-1]*nums[i]);
            result = max(result, maxs[i]);
        }

        return result;
    }
};