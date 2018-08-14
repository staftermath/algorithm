//
// Created by gwengww on 8/13/18.
// 404ms 8.34%
// time O(n*n)
// space O(n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size<=2) return {};
        vector<vector<int>> result;
        unordered_set<int> hash;
        for (int i=0; i<size; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            hash.clear();
            for (int j=i+1; j<size; j++) {
                if (hash.find(-nums[j]-nums[i]) != hash.end()) {
                    vector<int> new_entry = {nums[i], nums[j], -nums[i]-nums[j]};
                    sort(new_entry.begin(), new_entry.end());
                    result.push_back(new_entry);
                } else {
                    hash.insert(nums[j]);
                }
            }
        }
        auto it = unique(result.begin(), result.end());
        result.resize(it-result.begin());
        return result;
    }
};