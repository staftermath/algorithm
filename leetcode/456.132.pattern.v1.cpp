//
// Created by gwengww on 8/26/18.
// 88ms 32.78%
// time O(n*n)
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
            if (hash.begin()->first == nums[i]) continue;
            if (hash.begin()->first > nums[i]) {
                hash[nums[i]] = nums[i];
                continue;
            }
            p_upper = hash.begin();
            for (; p_upper!=hash.end() && p_upper->first < nums[i]; p_upper++) {
                if (p_upper->second > nums[i]) return true;
            }
            p_upper--;
            p_upper->second = nums[i];
        }
        return false;

    }
};