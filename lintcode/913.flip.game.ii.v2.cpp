//
// Created by gwengww on 6/17/18.
// 137ms 93.55%

class Solution {
public:
    /**
     * @param s: the given string
     * @return: if the starting player can guarantee a win
     */
    bool canWin(string &s) {
        // write your code here
        int size=s.size();
        unordered_map<string, bool> hash;
        return canWin(s, hash);
    }

    bool canWin(string &s, unordered_map<string, bool>& hash) {
        // write your code here
        int size=s.size();
        bool result;
        for (int i=0; i<size-1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = '-'; s[i+1] = '-';
                if (hash.find(s) == hash.end()) {
                    hash[s] = canWin(s, hash);
                }
                result = !hash[s];
                s[i] = '+'; s[i+1] = '+';
                if (result) return result;
            }
        }
        return false;
    }
};