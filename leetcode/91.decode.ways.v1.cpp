//
// Created by gwengww on 9/20/18.
// 0ms 100.00%
// time O(n)
// space O(1)

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (size == 0) return 0;
        int last=1, before_last=1, this_pos, tmp;
        if (s[0] == '0') return 0;
        for (int i=1; i<size; i++) {
            this_pos = 0;
            if (s[i] != '0') this_pos+=last;
            else if (s[i-1] != '1' && s[i-1] != '2') return 0;
            tmp = stoi(s.substr(i-1,2));
            if (tmp > 9 && tmp <=26) this_pos += before_last;
            before_last = last;
            last = this_pos;
        }
        return this_pos;
    }
};