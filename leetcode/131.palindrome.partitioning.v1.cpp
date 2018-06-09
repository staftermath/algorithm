//
// Created by gwengww on 6/6/18.
// 55.73%

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        vector<vector<string>> res;
        vector<string> path = {};
        partition(s, path, 0, res);
        return res;
    }
private:
    void partition(string& s, vector<string>& path, int index, vector<vector<string>>& res) {
        if (index>=s.size()) {
            res.push_back(path);
            return;
        }

        for (int i=index; i<s.size(); i++) {
            if (is_palindrome(s, index, i)) {
                auto tmp(path);
                tmp.push_back(s.substr(index, i-index+1));
                partition(s, tmp, i+1, res);
            }
        }
    }
    bool is_palindrome(string& s, int b, int e) {
        while (e>=b) {
            if (s[b++] != s[e--]) return false;
        }
        return true;
    }
};