//
// Created by gwengww on 5/3/18.
// beat 82.36%

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <=1) return s;
        int max_left = 0;
        int max_length = 1;
        for (int i=0; i<s.size()-max_length/2; i++) {
            int start = i-1;
            int end = i+1;
            while (start >=0 && end< s.size() && s[start] == s[end]) {
                start--;
                end++;
            }
            if (end-start-1 > max_length) {
                max_length = end-start-1;
                max_left=start+1;
            }
            start=i;
            end=i+1;
            while (start >=0 && end<s.size() && s[start] == s[end]) {
                start--;
                end++;
            }
            if (end-start-1 > max_length) {
                max_length = end-start-1;
                max_left=start+1;
            }
        }
        return s.substr(max_left, max_length);
    }
};