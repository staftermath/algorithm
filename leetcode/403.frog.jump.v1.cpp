//
// Created by gwengww on 6/30/18.
// 285ms 12.14%
// O(nlogn)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int size = stones.size();
        if (size <= 1) return true;
        vector<vector<int>> dp(size, vector<int>(size, 0));
        if (stones[1] != 1) return false;
        if (size == 2) return true;
        dp[1][1] = 1;
        for (int i=1; i<size-1; i++) {
            for (int j = 1; j<=i; j++) {
                if (dp[j][i] == 1) {
                    for (int k = max(1, j-1); k <=j+1; k++) {
                        auto next_step = find(stones.begin()+i+1, stones.end(), stones[i]+k);
                        if (next_step != stones.end()) {
                            // cout << "marking " << next_step - stones.begin() << "th stone reachable by jumping " << k << "steps from " << i << endl;
                            dp[k][next_step - stones.begin()] = 1;
                        }
                    }
                }
            }
        }

        for (int j=1; j<size; j++) {
            if (dp[j][size-1] == 1) return true;
        }
        return false;

    }
};