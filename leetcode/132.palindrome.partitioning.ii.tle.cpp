//
// Created by gwengww on 6/6/18.
//

class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0) return 0;
        vector<int> dp(s.size(), 0);
        for (int i=1; i<s.size(); i++) {
            minCut(s, i, dp);
        }
        return dp.back();
    }
private:
    void minCut(string& s, int index, vector<int>& dp) {
        int minimum = dp[index-1]+1;
        if (is_palindrome(s, 0, index)) {
            dp[index] = 0;
            return;
        }
        for (int i=1; i<index; i++) {
            if (dp[i-1]+1 < minimum && is_palindrome(s, i, index)) minimum = min(minimum, dp[i-1]+1);
        }
        dp[index] = minimum;
        return;
    }
    bool is_palindrome(string& s, int b, int e) {
        while (e>=b) {
            if (s[e--] != s[b++]) return false;
        }
        return true;
    }
};