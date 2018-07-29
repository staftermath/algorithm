//
// Created by gwengww on 7/28/18.
// 124ms 90.07%
// time O(nlogn) ?
// space O(1) ?

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <=1) return 0;
        return T(nums.begin(), nums.end());
    }

    int T(vector<int>::iterator from, vector<int>::iterator to) {
        if (from+1>=to) return 0;
        int count=0;
        if (from+2==to) {
            if (*from >*(to-1)*2L) count=1;
            sort(from,to);
            return count;
        }
        vector<int>::iterator mid=from+(to-from)/2;
        count += T(from, mid) + T(mid, to);
        vector<int>::iterator left = from, right=mid;
        while (left < mid && right < to) {
            int temp=0;
            while (right < to && *left > *right*2L) {
                right++;
                temp++;
            }
            count += temp*(mid-left);
            left++;
        }
        inplace_merge(from, mid, to);
        return count;
    }
};