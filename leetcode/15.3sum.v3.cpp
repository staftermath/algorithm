//
// Created by gwengww on 8/13/18.
// 72ms 78.80%
// time O(n*n)
// space O(1)
// optimized skip

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size<=2) return {};
        vector<vector<int>> result;
        int head, tail;
        for (int i=0; i<size; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            head = i+1;
            tail = size-1;
            while (head < tail) {
                if (nums[head]+nums[tail]==-nums[i]) {
                    result.emplace_back(initializer_list<int>{nums[i], nums[head], nums[tail]});
                    head++;
                    tail--;
                    while (nums[head]==nums[head-1]) head++;
                    while (nums[tail] == nums[tail+1]) tail--;
                }
                else if (nums[head]+nums[tail] < -nums[i]) head++;
                else tail--;
            }
        }
        return result;
    }
};