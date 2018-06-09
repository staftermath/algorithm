//
// Created by gwengww on 6/7/18.
// very bad

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        sort(nums.begin(), nums.end());
        // vector<int> picked(nums.size(), 0);
        vector<int> max_set = {nums[0]};
        for (int i=0; i<nums.size()-1; i++) {
            // if (!picked[i]) {
            vector<int> current_set = {nums[i]};
            grow_tree(i, nums, max_set, current_set);
            // }
        }
        return max_set;
    }
private:
    void grow_tree(int start, vector<int>& nums, vector<int>& max_set, vector<int>& current_set) {
        for (int i=start+1; i<nums.size(); i++) {
            if (nums[i] % nums[start] == 0) {
                auto search = find(max_set.begin(), max_set.end(), nums[i]);
                if (search != max_set.end() && search - max_set.begin() > current_set.size()) return;
                current_set.push_back(nums[i]);
                grow_tree(i, nums, max_set, current_set);
                if (current_set.size() > max_set.size()) max_set = current_set;
                // picked[i] = 0;
                current_set.pop_back();
            }
        }

    }
};