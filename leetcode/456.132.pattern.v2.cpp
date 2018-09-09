//
// Created by gwengww on 8/26/18.
// 28ms 41.27%
// time O(n*logn)
// space O(n)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if (size <=2) return false;
        map<int, int> hash;
        map<int, int>::iterator p_upper;
        int i=1;
        while (i<size && nums[i] <= nums[i-1]) i++;
        if (i == size) return false;
        hash[nums[i-1]] = nums[i];
        i++;
        for (; i<size; i++) {
            // cout << "at " << i << endl;
            if (hash.begin()->first == nums[i]) continue;
            if (hash.begin()->first > nums[i]) {
                hash[nums[i]] = nums[i];
                continue;
            }
            p_upper = hash.upper_bound(nums[i]);
            if (p_upper == hash.end()) {
                p_upper--;
                if (p_upper->first == nums[i]) {
                    p_upper--;
                    p_upper->second = nums[i];
                    continue;
                }
                if (p_upper->second > nums[i]) return true;
                p_upper->second = nums[i];
                continue;
            }
            p_upper--;
            if (p_upper->first == nums[i]) {
                p_upper--;
            }
            // cout << "(" << p_upper->first << "," << p_upper->second << ")" << endl;
            if (p_upper->second > nums[i]) return true;
            p_upper->second = nums[i];
        }
        return false;

    }
};