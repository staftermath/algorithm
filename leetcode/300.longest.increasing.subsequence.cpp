//
// Created by gwengww on 6/9/18.
// beat 95.18%
// time nlogn
// space n

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), last_int(nums.size()+1, INT_MAX);
        if (nums.size() <= 1) return nums.size();
        last_int[0] = INT_MIN;
        for (int i=0; i<nums.size(); i++) {
            int k = search_first_smaller(last_int, nums[i]);
            last_int[k+1] = nums[i];
            dp[i] = k+1;
        }
        int maximum = 1;
        for (int i=0; i<nums.size(); i++) {
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }
private:
    int search_first_smaller(vector<int>& v, int val) {
        int start =0, mid = v.size()/2, end=v.size();
        while (start +1 < end) {
            if (v[mid] >= val) {
                end = mid;
            } else {
                start = mid;
            }
            mid = (start+end)/2;
        }
        if (end == v.size()) return start;
        return (v[end] >= val)? start: end;

    }
};