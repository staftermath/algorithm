//
// Created by gwengww on 6/2/18.
// beat 51.04%
// improve from v1 by iterator backwards in each step.
// preventing initiation
// don't need extra maximum iteration
// can still be improved

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        auto counts = count_0_1(strs);
        for (int i=0; i<counts.size(); i++) {
            total_combination(counts, dp, i, m, n);
        }
        return dp[m][n];
    }
private:
    vector<pair<int, int>> count_0_1(vector<string>& strs) {
        vector<pair<int, int>> all_counts;
        for (auto& str: strs) {
            pair<int, int> counts;
            for (auto& chr: str) {
                if (chr == '0') {
                    counts.first++;
                } else {
                    counts.second++;
                }
            }
            all_counts.push_back(counts);
        }
        return all_counts;
    }
    void total_combination(vector<pair<int, int>>& all_counts, vector<vector<int>>& dp, int position, int max_0, int max_1) {
        pair<int, int>& this_pair = all_counts[position];
        for (int i=max_0; i>=this_pair.first; i--) {
            for (int j=max_1; j>=this_pair.second; j--) {
                dp[i][j] = max(dp[i][j], dp[i-this_pair.first][j-this_pair.second]+1);
            }
        }
    }
};