//
// Created by gwengww on 6/18/18.
// 620ms 81.80%
// time O(n)
// space O(k)

class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        if (s.size() == 0 || k == 0) return 0;
        if (s.size() <= k) return s.size();
        unordered_map<char, int> hash;
        hash[s[0]] = 1;
        int begin=0, end=1, maximal=1;
        while (end < s.size()) {
            // cout << begin << " to " << end <<endl;
            if (hash.find(s[end]) != hash.end() || hash.size() < k) {
                hash[s[end]]++;
                maximal = max(maximal, end-begin+1);
                end++;
            } else {
                hash[s[begin]]--;
                if (hash[s[begin]] == 0) hash.erase(s[begin]);
                begin++;
            }
        }
        return maximal;
    }

};