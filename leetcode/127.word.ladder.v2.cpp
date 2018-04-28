//
// Created by gwengww on 4/28/18.
// must convert vector<string> wordList to unordered_set<string> to prevent rearrange vector element when erase
// beat 90%

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 1;
        unordered_set<string> wordDict = {};
        for (auto v: wordList) {
            if (v != beginWord) wordDict.insert(v);
        }
        auto findEndWord = wordDict.find(endWord);
        if ( findEndWord == wordDict.end()) return 0; // endWord must be in the dict
        wordDict.erase(findEndWord);

        unordered_set<string> vbegin = {beginWord};
        unordered_set<string> vend = {endWord};
        unordered_set<string> *begin, *end;
        begin = &vbegin;
        end = &vend;
        while (!begin->empty() && !end->empty()) {
            if (begin->size() > end->size()) {
                auto temp = end;
                end = begin;
                begin = temp;
            }
            length++;
            unordered_set<string> tempSet; // have
            for (auto p=begin->begin(); p!=begin->end(); p++) {
                string thisWord = *p;
                for (int i=0; i<thisWord.size(); i++) {
                    for (int j=0; j<26; j++) {
                        string temp(thisWord);
                        temp[i] = 'a'+j;
                        if (end->find(temp) != end->end()) {
                            // cout << "found " << temp << endl;
                            return length;
                        }
                        auto search = wordDict.find(temp);
                        if (search != wordDict.end()) {
                            tempSet.insert(temp);
                            wordDict.erase(search);
                        }
                    }
                }
            }
            swap(*begin, tempSet);
        }
        return 0;
    }
};