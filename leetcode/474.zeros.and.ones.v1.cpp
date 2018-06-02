//
// Created by gwengww on 6/2/18.
// beat 28%
// can be improved. see v2

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        auto counts = count_0_1(strs);
        // cout << "counted" << endl;
        // for (auto cnt: counts) {
        //     cout << "(" << cnt.first << "," << cnt.second << ");" << flush;
        // }
        // cout << endl;
        for (int i=0; i<counts.size(); i++) {
            total_combination(counts, dp, i, m, n);
            // cout << "include string up to " << i << " DP status" << endl;
            // for (int k=0; k<=m; k++) {
            //     for (int l=0; l<=n; l++) {
            //         cout << dp[k][l] << "," << flush;
            //     }
            //     cout << endl;
            // }
        }
        int maximum = 0;
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                maximum = max(dp[i][j], maximum);
            }
        }
        return maximum;
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
        vector<vector<int>> new_dp(dp);
        for (int i=this_pair.first; i<=max_0; i++) {
            for (int j=this_pair.second; j<=max_1; j++) {
                new_dp[i][j] = max(dp[i][j], dp[i-this_pair.first][j-this_pair.second]+1);
            }
        }
        dp = new_dp;
    }
};