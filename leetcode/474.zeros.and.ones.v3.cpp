//
// Created by gwengww on 6/2/18.
// beat 94.00%
// no need to pre calculate and initiate count of 0s and 1s in a string.
// only count when iterated.

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i=0; i<strs.size(); i++) {
            total_combination(strs, dp, i, m, n);
        }
        return dp[m][n];
    }
private:
    void total_combination(vector<string>& strs, vector<vector<int>>& dp, int position, int max_0, int max_1) {
        int zeros = count(strs[position].begin(), strs[position].end(), '0');
        int ones = strs[position].size()-zeros;
        for (int i=max_0; i>=zeros; i--) {
            for (int j=max_1; j>=ones; j--) {
                dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
            }
        }
    }
};