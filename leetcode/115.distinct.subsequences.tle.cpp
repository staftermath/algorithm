//
// Created by gwengww on 6/5/18.
//

class Solution {
public:
    int numDistinct(string s, string t) {
        int count = 0;
        helper(s, t, 0, 0, count);
        return count;
    }
private:
    void helper(string& s, string& t, int s_start, int t_start, int& count) {
        if (t_start == t.size()) count++;
        for (int i=s_start; i<s.size(); i++) {
            if (s[i] == t[t_start]) {
                helper(s, t, i+1, t_start+1, count);
            }
        }
        return;
    }
};