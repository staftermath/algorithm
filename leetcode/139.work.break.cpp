//
// Created by gwengww on 4/27/18.
//

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return false;
        if (wordDict.size() == 0) return false;
        hashDict(wordDict);
        int minimum = hash.begin()->first;
        vector<bool> result = vector<bool>(s.size(), false);
        for (int i=minimum-1; i<s.size(); i++) {
            bool marked = false;
            for(auto pair: hash) {
                if (marked) break;
                int size = pair.first;
                if (size > i+1) break;
                if (i-size >= 0 && !result[i-size]) continue;
                for (auto v: pair.second) {
                    if (marked) break;
                    if (s.substr(i-size+1, size) == v) {
                        result[i] = true;
                        marked = true;
                        break;
                    }
                }
            }
        }
        return result[s.size()-1];
    }
private:
    map<int, vector<string>> hash;

    void hashDict(vector<string>& wordDict) {
        for (auto v: wordDict) {
            if (hash.find(v.size()) != hash.end()) {
                hash[v.size()].push_back(v);
            } else {
                hash[v.size()] = {v};
            }
        }
    }

