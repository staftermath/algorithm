//
// Created by gwengww on 6/7/18.
// beat 100% (thanks solution)
// any substring is only checked once for is_palindrome
// space: O(N)
// time: O(N^2) ?

class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        if (size<=1) return 0;
        vector<int> dp(size+1, 0);
        for (int i=0; i<=size; i++) dp[i] = i-1;
        for (int i=0; i<=size; i++) {
            for (int j=0; i-j>=0 && i+j < size && s[i-j]==s[i+j]; j++) {
                dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1);
            }
            for (int j=0; i-j>=0 && i+j+1<size && s[i-j] == s[i+j+1]; j++) {
                dp[i+j+2] = min(dp[i+j+2], dp[i-j]+1);
            }
        }
        return dp.back();
    }
};