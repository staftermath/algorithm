//
// Created by gwengww on 4/28/18.
// beating 96.53%
// time complexity O(N) ???
// space complexity ???

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word: wordDict) {
            if (wordDictHash.find(word.size()) != wordDictHash.end()) {
                wordDictHash[word.size()].insert(word);
            } else {
                wordDictHash[word.size()] = {word};
            }

        }
        helper(s, 0);
        if (hash[0].size() == 0) return {};
        vector<string> result = {};
        for (string v: hash[0]) {
            result.push_back(v);
        }
        return result;
    }
private:
    map<int, unordered_set<string>> wordDictHash = {};
    unordered_map<int, unordered_set<string>> hash = {};
    void helper(string& s, int start) {
        unordered_set<string> result = {};
        for (auto p=wordDictHash.begin(); p!=wordDictHash.end(); p++) {
            if (p->first > s.size() - start) break; // the rest words in dict will be longer than the remaining string
            int size = p->first;
            auto head = p->second.find(s.substr(start, size));
            if (head != p->second.end()) {
                string v = *head;
                if (s.size() - start == size) {
                    result.insert(v);
                    break; // end of string
                }
                // may be able to add this word to the remaining string to construt the full string
                auto pPartStrings = hash.find(start+size); // find about s.substr(p->first+1)
                if (pPartStrings == hash.end()) {
                    // not hashed
                    helper(s, start+size); // hash it
                    pPartStrings = hash.find(start+size); // find the hash again;
                }
                // should be hashed now.
                for (auto w: pPartStrings->second) {
                    // iterate over combination of strings
                    result.insert(v + " " + w);
                }
            }
        }
        hash[start] = result;
    }
};