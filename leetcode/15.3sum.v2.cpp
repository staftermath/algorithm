//
// Created by gwengww on 8/13/18.
// 80ms 42.57%
// time O(n*n)
// space O(1)

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
                if (head>i+1 && nums[head]==nums[head-1]) {
                    head++;
                    continue;
                }
                if (tail<size-1 && nums[tail] == nums[tail+1]) {
                    tail--;
                    continue;
                }
                if (nums[head]+nums[tail]==-nums[i]) {
                    result.emplace_back(initializer_list<int>{nums[i], nums[head], nums[tail]});
                    head++;
                    tail--;
                }
                else if (nums[head]+nums[tail] < -nums[i]) head++;
                else tail--;
            }

        }
        // auto it = unique(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b){return a[0]==b[0] && a[1]==b[1];});
        // result.resize(it-result.begin());
        return result;
    }
};