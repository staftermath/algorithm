//
// Created by gwengww on 6/23/18.
//

//
// Created by gwengww on 6/23/18.
//

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        if (hash.find(endWord) == hash.end()) return {};
        if (hash.find(beginWord) != hash.end()) hash.erase(beginWord);
        vector<vector<string>> result;
        unordered_set<string> visited;
        queue<vector<string>> que;
        que.push({beginWord});
        int minLength = INT_MAX;
        int level = 1;

        while (!que.empty()) {
            auto path = que.front();
            que.pop();
            if (path.size() > level) {
                for (auto& w: visited) {
                    hash.erase(w);
                }
                visited.clear();
                if (minLength <= path.size() && path.back()!=endWord) break;
                level = path.size();
            }
            string word = path.back();
            if (word == endWord) {
                result.push_back(path);
                minLength = min(minLength, int(path.size()));
            } else {
                // extend path
                for (int i=0; i<word.size(); i++) {
                    char tmp = word[i];
                    for (int j=0; j<26; j++) {
                        word[i] = 'a'+j;
                        if (hash.find(word) != hash.end()) {
                            path.push_back(word);
                            que.push(path);
                            visited.insert(word);
                            path.pop_back();
                        }
                    }
                    word[i] = tmp;
                }
            }
        }
        return result;
    }
};