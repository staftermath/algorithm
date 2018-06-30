//
// Created by gwengww on 6/28/18.
// 22ms, 63.79%
// time O(N)
// space O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> hash;
        vector<int> cache;
        map<int, vector<int>> bucket;
        for (int i=0; i<size; i++) {
            if (hash.find(nums[i]) == hash.end()) cache.emplace_back(nums[i]);
            hash[nums[i]]++;
        }
        if (cache.size() <=k) return cache;
        for (int i=0; i<cache.size(); i++) {
            bucket[hash[cache[i]]].emplace_back(i);
        }
        vector<int> result(k);
        int i = 0;
        auto ptr = bucket.end();
        ptr--;
        while (i<k) {
            int j=0;
            while (i<k && j< ptr->second.size()) {
                result[i++] = cache[ptr->second[j++]];
            }
            ptr--;
        }
        return result;
    }
};