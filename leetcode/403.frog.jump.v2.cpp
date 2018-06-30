//
// Created by gwengww on 6/30/18.
// 126ms 45.20%


class Solution {
public:
    bool canCross(vector<int>& stones) {
        int size = stones.size();
        if (size <= 1) return true;
        // vector<vector<int>> dp(size, vector<int>(size, 0));
        unordered_map<int, unordered_set<int>> dp; // stone x can be reached by jumping y steps;
        if (stones[1] != 1) return false;
        if (size == 2) return true;
        dp[stones[1]] = {1};
        unordered_set<int> hash(stones.begin()+1, stones.end());
        for (int i=1; i<size-1; i++) {
            // remove previous stones
            hash.erase(stones[i]);
            vector<int> possible_jump;
            // find all possible length for next jumps
            for (auto& p: dp[stones[i]]) {
                possible_jump.emplace_back(p);
                possible_jump.emplace_back(p+1);
                if (p>1) possible_jump.emplace_back(p-1);
            }
            if (!possible_jump.empty()) {
                // can any of these jumps land to a stone?
                for (auto& jump: possible_jump) {
                    if (hash.find(stones[i]+jump) != hash.end()) {
                        dp[stones[i]+jump].insert(jump);
                    }
                }
            }
        }
        return dp.find(stones[size-1]) != dp.end();

    }
};