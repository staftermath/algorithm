//
// Created by gwengww on 5/3/18.
// beat 80.64%

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        int start, end;
        for (int i=0; i<s.size(); i++) {
            result++;
            start = i-1;
            end = i+1;
            while (start >=0 && end<s.size() && s[start] == s[end]) {
                result++;
                start--;
                end++;
            }
            start = i;
            end = i+1;
            while (start >=0 && end<s.size() && s[start] == s[end]) {
                result++;
                start--;
                end++;
            }
        }
        return result;
    }
};