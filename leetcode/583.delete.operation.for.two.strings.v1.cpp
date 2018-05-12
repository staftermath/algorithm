//
// Created by gwengww on 5/8/18.
// TLE

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1 == word2) return 0;
        if (word2.size() == 0) return word1.size();
        if (word1.size() == 0) return word2.size();
        if (word1.size() > word2.size()) {
            return helper(word1, word2);
        } else {
            return helper(word2, word1);
        }

    }
private:
    int helper(string longer, string shorter) {
        if (longer.find(shorter) != string::npos) return longer.size() - shorter.size();
        int minimum = longer.size() + shorter.size();
        if (longer.size() < shorter.size()) {
            string temp = shorter;
            shorter = longer;
            longer = temp;
        }
        for (int i=0; i<longer.size(); i++) {
            string temp = longer;
            temp.erase(i, 1);
            // cout << temp << endl;
            minimum = min(minimum, helper(temp, shorter)+1);
        }
        return minimum;
    }
};