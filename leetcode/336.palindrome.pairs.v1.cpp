//
// Created by gwengww on 7/26/18.
// 324ms 11.91%
// time O(n^2)
// space O(n)

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int size = words.size();
        if (size<=1) return {};
        int empty_word_index = -1;
        vector<int> sizes(size);
        for (int i=0; i<size; i++) {
            sizes[i] = words[i].size();
            if (sizes[i] == 0) empty_word_index = i;
        }
        // cout << empty_word_index << endl;
        queue<int> candidates;
        vector<vector<int>> result;
        vector<int> palindrome_pair = {-1, -1};
        for (int i=0; i<size; i++) {
            if (i==empty_word_index) {
                for (int j=0;j<size; j++) {
                    if (j!=i && isPalindrome(words[j], 0, sizes[j]-1)) {
                        // cout << "got " << i << "," << j << endl;
                        palindrome_pair = {i, j};
                        result.emplace_back(palindrome_pair);
                        palindrome_pair = {j, i};
                        result.emplace_back(palindrome_pair);
                    }
                }
                continue;
            }
            for (int j=0; j<size; j++) {
                if (i!=j && j!= empty_word_index && words[j][sizes[j]-1] == words[i][0]) candidates.push(j);
            }
            while (!candidates.empty()) {
                int j = candidates.front();
                candidates.pop();
                // if (sizes[] == 0 && isPalindrome(words[j], 0, sizes[j]-1)) {
                //     vector<int> palindrome_pair = {i,j};
                //     result.emplace_back(palindrome_pair);
                //     continue;
                // }
                // if (sizes[i] == 0 && isPalindrome(words[j], 0, sizes[j]-1)) {
                //     vector<int> palindrome_pair = {i,j};
                //     result.emplace_back(palindrome_pair);
                //     continue;
                // }
                int total_size = sizes[i]+sizes[j];
                int k=1;
                for (; k<sizes[i] && k<sizes[j]; k++) {
                    if (words[i][k] != words[j][sizes[j]-k-1]) break;
                }
                // cout << "k is " << k << endl;
                if (k>=sizes[j] && isPalindrome(words[i], k, sizes[i]-1) || k>=sizes[i] && isPalindrome(words[j], 0, sizes[j]-1-k)) {
                    // cout << "also got " << i << "," << j << endl;
                    palindrome_pair = {i,j};
                    result.emplace_back(palindrome_pair);
                    continue;
                }
            }
        }

        return result;
    }

    bool isPalindrome(string& word, int from, int end) {
        if (from > end || word.size() == 0) return true;
        while (from <= end) {
            if (word[from] != word[end]) return false;
            from++;
            end--;
        }
        return true;
    }
};