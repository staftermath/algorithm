//
// Created by gwengww on 9/23/18.
// 20ms 81.99%
// time O(N*K) N = amount K = coins
// space O(N)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        while (coins.back() > amount) {
            coins.pop_back();
        }
        if (coins.empty()) return -1;
        if (coins.size() == 1) return (amount%coins[0] == 0)? amount/coins[0]: -1;
        vector<int> dp(amount+1, INT_MAX);
        for (auto coin: coins) {
            dp[coin] = 1;
        }

        for (int i=1; i<= amount; i++) {
            if (dp[i] == INT_MAX) continue;
            for (auto coin: coins) {
                if (i+coin <= amount) dp[i+coin] = min(dp[i]+1, dp[i+coin]);
            }
        }
        return (dp[amount] == INT_MAX)? -1: dp[amount];

    }
};