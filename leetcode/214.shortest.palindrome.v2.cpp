//
// Created by gwengww on 7/31/18.
// 4ms 97.81%
// KMP
// time O(n)
// space O(n)

class Solution {
public:
    string shortestPalindrome(string s) {
        string reversed = s;
        int size = s.size();
        reverse(reversed.begin(), reversed.end());
        string full = s+"#"+reversed;
        vector<int> lps(2*size+1);
        int len=0, i=1;
        while (i<2*size+1) {
            if (full[i] == full[len]) {
                len++;
                lps[i] = len;
                i++;
            } else if (len==0) {
                lps[i] = len;
                i++;
            } else {
                len = lps[len-1];
            }
        }
        int l = lps.back();
        return reversed.substr(0, size-l) + s;
    }
};