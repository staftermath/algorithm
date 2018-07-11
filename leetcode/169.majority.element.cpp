//
// Created by gwengww on 7/4/18.
// 12ms 99.92%
// Moore's Voting Algorithm
// time O(n)
// space O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() <=2) return nums[0];
        int majority_index=0, count=1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[majority_index] == nums[i]) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                majority_index = i;
                count = 1;
            }
        }
        return nums[majority_index];
    }
};