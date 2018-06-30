//
// Created by gwengww on 6/28/18.
// 8ms 53.81%
// time O(N)
// space O(1)
// can be improved by not using vector
// instead use: int big, small;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) return false;
        vector<int> cache = {nums[0]};
        int i = 1;
        while (i<size && nums[i] <= nums[i-1]) {
            cache[0] = nums[i++];
        }
        if (i<size) cache.emplace_back(nums[i++]);
        for (; i<nums.size(); i++) {
            // first will also push_back
            if (nums[i] > cache.back()) return true;
            else {
                if (nums[i] > cache[0]) cache[1] = nums[i];
                else cache[0] = nums[i];
            }
        }
        return false;
    }
};