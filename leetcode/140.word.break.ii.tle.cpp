//
// Created by gwengww on 4/28/18.
// TLE

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result = {};
        if (!sorted) {
            sort(wordDict.begin(), wordDict.end(), [](const string& a, const string& b){return a.size() > b.size();});
            sorted = true;
        }
        for (string word: wordDict) {
            if (word.size() <= s.size() && s.substr(0, word.size()) == word) {
                if (word.size() == s.size()) {
                    result.push_back(word);
                } else {
                    vector<string> rest = wordBreak(s.substr(word.size()), wordDict);
                    for (string v: rest) {
                        result.push_back(word+" "+v);
                    }
                }
            }
        }
        return result;
    }
private:
    bool sorted = false;
};