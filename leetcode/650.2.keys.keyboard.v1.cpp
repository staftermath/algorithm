//
// Created by gwengww on 8/15/18.
// 8ms 46.75%
// time O(n*log(n))
// space O(n)

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 2;
        dp[3] = 3;
        int j,q;
        for (int i=4;i<=n;i++) {
            j=2;
            dp[i]=i;
            while (j <= i/j) {
                if (i%j == 0) {
                    q = i/j;
                    dp[i] = min(dp[j]+q, dp[i]);
                    dp[i] = min(dp[q]+j, dp[i]);
                }
                j++;
            }
            // cout << dp[i] << endl;
        }
        return dp[n];
    }
};