//
// Created by gwengww on 6/9/18.
// beat 44.29% 316ms


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() <= 1) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(),
             [](const pair<int, int>& a, const pair<int, int>& b){
                 return a.first < b.first || a.first == b.first && a.second < b.second;
             });
        vector<int> dp(envelopes.size(), 1);
        int maximum = 1;
        for (int i=1; i<envelopes.size(); i++) {
            int k=i-1;
            while (envelopes[k].first == envelopes[i].first) k--;
            for (;k>=0;k--) {
                if (envelopes[k].second < envelopes[i].second) {
                    dp[i] = max(dp[i], dp[k]+1);
                }
            }
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }
};