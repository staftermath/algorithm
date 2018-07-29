//
// Created by gwengww on 7/28/18.
//

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <=1) return 0;
        return T(nums, 0, nums.size()-1);
    }

    int T(vector<int>& nums, int from, int to) {
        if (from>=to) return 0;
        if (from+1==to) {
            if (nums[from] >nums[to]*2L) return 1;
            else return 0;
        }
        int mid=(from+to)/2;
        int additional = 0;
        for (int i=from; i<=mid; i++) {
            for (int j=mid+1; j<=to; j++) {
                if (nums[i] > nums[j]*2L) additional++;
            }
        }
        return T(nums, from, mid) + T(nums, mid+1, to) + additional;
    }
};