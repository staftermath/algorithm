//
// Created by gwengww on 7/30/18.
// 176ms 14.99%
// time O(n^2);
// space O(n); (only stores additional char

class Solution {
public:
    string shortestPalindrome(string s) {
        int size = s.size();
        if (size<=1) return s;
        if (size&1==1) {
            // handle edge case
            int mid = size/2, k=mid;
            while (k>=1) {
                if (s[mid-k] != s[mid+k]) break;
                k--;
            }
            if (k==0) return s; // s is a palindrome of odd size;
        }
        string head;
        for (int i=size/2-1; i>=0; i--) {
            int k=i;
            // even size palindrome
            while (k>=0) {
                if (s[i-k] != s[i+k+1]) break;
                k--;
            }
            if (k<0) {
                addToHead(s, 2*i+1, head);
                return head+s;
            }
            // odd size palindrome
            k=i;
            while (k>=1) {
                if (s[i-k] != s[i+k]) break;
                k--;
            }
            if (k == 0) {
                addToHead(s, 2*i, head);
                return head+s;
            }
        }
    }

    void addToHead(string& s, int i, string& head) {
        int k = s.size()-1;
        while (k>i) {
            head += s[k--];
        }

    }
};