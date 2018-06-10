//
// Created by gwengww on 6/9/18.
// beat 94.06 %
// LIS (nlogn) optimal solution

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() <= 1) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(),
             [](const pair<int, int>& a, const pair<int, int>& b){
                 return a.first < b.first || a.first == b.first && a.second > b.second; // it's critical to put bigger second first
             });
        vector<int> dp(envelopes.size(), 1), last_doll(envelopes.size()+1, INT_MAX);
        last_doll[0] = INT_MIN;
        for (int i=0; i<envelopes.size(); i++) {
            int k = search_doll(last_doll, envelopes[i].second);
            last_doll[k+1] = envelopes[i].second;
            dp[i] = k+1;
        }
        int maximum = 1;
        for (int i=0; i< envelopes.size(); i++) {
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }
private:
    int search_doll(vector<int>& v, int val) {
        int start = 0, mid=v.size()/2, end = v.size();
        while (start + 1 < end) {
            if (v[mid] >= val) {
                end = mid;
            } else {
                start = mid;
            }
            mid = (start+end)/2;
        }
        if (end == v.size()) return start;
        return (v[end] >= val)? start: end;
    }
};