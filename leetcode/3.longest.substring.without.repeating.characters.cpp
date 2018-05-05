//
// Created by gwengww on 5/4/18.
// beating 77.85%
// time O(NM) where N is s length and M is longest substring length
// space O(1)
// can use

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int maximum = 1;
        int start = 0;
        int end = 0;
        while (end < s.size()) {
            end++;
            int local_maximum = end-start;
            auto search = find(s.begin()+start, s.begin()+end, s[end]);
            while (search == s.begin()+end && end < s.size()) {
                end++;
                local_maximum++;
                search = find(s.begin()+start, s.begin()+end, s[end]);
            }
            start = search - s.begin() + 1;
            maximum = max(local_maximum, maximum);
        }
        return maximum;
    }
};