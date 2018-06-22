//
// Created by gwengww on 6/21/18.
// 76ms 65.66%

class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here
        vector<Node> hash(26);
        for (int i=0; i<26; i++) {
            hash[i] = Node(i);
        }
        vector<int> found(26);
        // build topology
        bool checked = false;
        int i=0;
        for (; i<words.size()-1; i++) {
            checked = false;
            for (int j=0; j<words[i].size(); j++) {
                found[words[i][j]-'a'] = 1;
                if (!checked && j<words[i+1].size() && words[i][j]!=words[i+1][j]) {
                    // cout << "inserting out " << words[i][j] << endl;
                    hash[words[i][j]-'a'].out.insert(words[i+1][j]-'a');
                    // cout << "inserting in " << words[i+1][j] << endl;
                    hash[words[i+1][j]-'a'].in.insert(words[i][j]-'a');
                    found[words[i+1][j]-'a'] = 1;
                    checked = true;
                }

            }
        }
        for (int j=0; j<words[i].size(); j++) found[words[i][j]-'a'] = 1;

        string result = "";
        queue<Node> que;
        set<int> isolated;
        for (int i=0; i<26; i++) {
            if (hash[i].in.empty() && found[hash[i].chr] == 1) {
                if (hash[i].out.empty() ) isolated.insert(hash[i].chr);
                else que.push(hash[i]);
                found[hash[i].chr] = 0;
            }
        }

        while (!que.empty()) {
            // cout << "===" << endl;
            // for (auto& p: hash) {
            //     cout << p.first << ": " << flush;
            //     for (auto& chr: p.second.in) {
            //         cout << chr << "," << flush;
            //     }
            //     cout << endl;
            // }
            auto node = que.front();
            que.pop();
            // cout << "at " << node.chr << endl;
            result += char('a'+node.chr);
            // cout << result << endl;
            for (auto& c: node.out) {
                hash[c].in.erase(node.chr);
                if (hash[c].in.empty()) {
                    // cout << "pushing in " << 'a'+c << endl;
                    que.push(hash[c]);
                }
            }
        }
        for (int i=0; i<26; i++){
            if (!hash[i].in.empty()) return "";
        }
        for (auto& p: isolated) {
            int i=0;
            for (; i<result.size(); i++) {
                if (result[i]>'a'+p) {
                    result.insert(i, 1, char('a'+p));
                    break;
                }
            }
            if (i==result.size()) result += char('a'+p);
        }
        return result;
    }

    struct Node {
        unordered_set<int> in;
        unordered_set<int> out;
        int chr;
        Node() {};
        Node(int chr): chr(chr) {};
    };
};