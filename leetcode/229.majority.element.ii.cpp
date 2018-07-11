//
// Created by gwengww on 7/4/18.
// 8ms 100%
// time O(n)
// space O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority_1=0, majority_2=1, count_1=0, count_2=0, n=nums.size();
        if (n==0) return {};
        for (int i=0; i<n;i++) {
            if (nums[i] == nums[majority_1]) count_1++;
            else if (nums[i] == nums[majority_2]) count_2++;
            else if (count_1 == 0) {
                majority_1 = i;
                count_1 = 1;
            } else if (count_2 == 0) {
                majority_2 = i;
                count_2 = 1;
            } else {
                count_1--;
                count_2--;
            }
        }
        count_1 = 0;
        count_2 = 0;
        for (int j=0; j<n; j++) {
            if (nums[j] == nums[majority_1]) count_1++;
            else if (nums[j] == nums[majority_2]) count_2++;
        }
        vector<int> result;
        if (count_1 > n/3) result.emplace_back(nums[majority_1]);
        if (count_2 > n/3) result.emplace_back(nums[majority_2]);
        return result;
    }
};