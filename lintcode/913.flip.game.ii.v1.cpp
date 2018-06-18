//
// Created by gwengww on 6/17/18.
// 436ms 16.63%
// O(N!)

class Solution {
public:
    /**
     * @param s: the given string
     * @return: if the starting player can guarantee a win
     */
    bool canWin(string &s) {
        // write your code here
        int size=s.size();
        vector<int> nim(size+1);
        vector<int> happen(size+1);
        for (int i=0; i<size-1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = '-'; s[i+1] = '-';
                bool result = !canWin(s);
                s[i] = '+'; s[i+1] = '+';
                if (result) return result;
            }
        }
        return false;
    }
};