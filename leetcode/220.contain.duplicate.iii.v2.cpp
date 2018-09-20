//
// Created by gwengww on 9/19/18.
// 20 ms 26.16%
// time O(logk*n)
// space O(k)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty()) return false;
        if (k == 0) return false;
        set<long> hash;
        hash.insert(nums[0]);
        // set<int> test = {1,3,4,5};
        // cout << *(test.lower_bound(7)) << endl;
        for (int i=1; i<nums.size(); i++) {
            auto l = hash.lower_bound(long(nums[i])-t);
            if (l!=hash.end() && *l <= long(nums[i])+t) return true;
            if (hash.size() >= k) hash.erase(nums[i-k]);
            hash.insert(long(nums[i]));
        }
        return false;
    }
};