//
// Created by gwengww on 8/15/18.
// 0ms 100%
// time O(n*n)
// space O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0]+nums[1]+nums[2], candidate;
        int size = nums.size(), head, tail;
        sort(nums.begin(), nums.end());
        for (int i=0; i<size-2; i++) {
            while (i>0 && i<size-2 && nums[i] == nums[i-1]) i++;
            head=i+1, tail=size-1;
            while (head+1 < tail) {
                candidate = nums[i]+nums[head]+nums[tail];
                if (abs(result-target) > abs(candidate-target)) result = candidate;
                if (candidate == target) return target;
                else if (candidate < target) head++;
                else tail--;
            }
            candidate = nums[i]+nums[head]+nums[tail];
            if (abs(result-target) > abs(candidate-target)) result = candidate;
        }
        return result;
    }
};