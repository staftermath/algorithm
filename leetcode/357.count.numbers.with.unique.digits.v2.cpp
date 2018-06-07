//
// Created by gwengww on 6/6/18.
// simple improvement. beat 100%

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n >= 11) return 0;
        if (n == 0) return 1;
        vector<int> dp(n+1, 0);
        int result = 1;
        dp[0] = 1;
        for (int i=1; i<=n; i++) {
            dp[i] = dp[i-1]*(9-i+1);
            result += dp[i]+(i-1)*dp[i-1];
        }
        return result;
    }
};