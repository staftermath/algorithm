//
// Created by gwengww on 7/21/18.
// 8ms 87.51%
// dp
// time O(n*m)
// space O(n*m)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size(), size2=word2.size();
        if (size1 == 0) return size2;
        if (size2 == 0) return size1;
        vector<vector<int>> dp(size1, vector<int>(size2));
        dp[0][0] = (word1[0] == word2[0])? 0: 1;
        for (int j=1; j<size2; j++) {
            dp[0][j] = (word1[0] == word2[j])? j: dp[0][j-1]+1;
        }
        for (int i=1; i<size1; i++) {
            dp[i][0] = (word1[i] == word2[0]) ? i: dp[i-1][0]+1;
        }
        for (int i=1; i<size1; i++) {
            for (int j=1; j<size2; j++) {
                if (word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        return dp[size1-1][size2-1];
    }
};