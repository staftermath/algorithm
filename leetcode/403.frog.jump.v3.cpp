//
// Created by gwengww on 6/30/18.
// better dp structure
// 105ms 62.99%

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int size = stones.size();
        if (size <= 1) return true;
        vector<unordered_set<int>> dp(size);
        if (stones[1] != 1) return false;
        if (size == 2) return true;
        dp[1].insert(1);
        unordered_map<int, int> hash;
        for (int i=1; i<size; i++) {
            hash[stones[i]] = i;
        }
        for (int i=1; i<size-1; i++) {
            // cout << "at " << i << "th stone" << endl;
            for (auto& jump: dp[i]) {
                int next_stone = stones[i]+jump+1;
                // jump+1 step
                // cout << "looking for " << next_stone << endl;
                if (hash.find(next_stone) != hash.end()) dp[hash.find(next_stone)->second].insert(jump+1);
                // jump step
                next_stone--;
                // cout << "looking for " << next_stone << endl;
                if (hash.find(next_stone) != hash.end()) dp[hash.find(next_stone)->second].insert(jump);
                // cout << "looking for " << next_stone << endl;
                next_stone--;
                // jump-1 step. only when jump > 1;
                if (jump>1) if (hash.find(next_stone) != hash.end()) dp[hash.find(next_stone)->second].insert(jump-1);
            }
        }
        return !dp.back().empty();

    }
};