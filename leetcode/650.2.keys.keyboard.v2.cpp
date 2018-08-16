//
// Created by gwengww on 8/15/18.
// 4ms 58.32%

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        for (int i=2; i<=n; i++) {
            dp[i] = i;
        }
        for (int i=2;i<=n;i++) {
            for (int k=2; k*i<=n; k++) {
                dp[k*i] = min(dp[k*i], dp[i]+k);
            }
        }
        return dp[n];
    }
};