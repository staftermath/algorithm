//
// Created by gwengww on 9/18/18.
// 228ms 7.35%
// time O(k*n)
// space O(1)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty()) return false;
        for (int i=1; i<nums.size(); i++) {
            for (int j=max(i-k, 0); j<i; j++) {
                if (abs(long(nums[j])-long(nums[i]))<=t) return true;
            }
        }
        return false;
    }
};