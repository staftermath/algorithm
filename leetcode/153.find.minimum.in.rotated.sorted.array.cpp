//
// Created by gwengww on 7/4/18.
// 0ms 100%
// time O(log(n))
// space O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, mid = (start+end)/2;
        while (start + 1 < end) {
            if (nums[mid] > nums[end]) {
                start = mid;
            } else {
                end = mid;
            }
            mid = (start+end)/2;
        }
        return (nums[start] < nums[end])? nums[start]: nums[end];
    }
};