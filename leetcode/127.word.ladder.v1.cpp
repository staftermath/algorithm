//
// Created by gwengww on 4/28/18.
// L: ladder length
// N: wordList length
// time complexity O(LN)
// space complexity O(N)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<ladder> result = {{beginWord, 1}};
        int used = 0;
        int endOfLastLadder = 0;
        vector<bool> vUsed(wordList.size(), false);
        while (used < wordList.size()) {
            int lastUsed = used;
            int size = result.size();
            for (int j=endOfLastLadder; j<size; j++){ // no need to look at previous ladder
                // cout << "checking: " << result[j].tail << "length: " << result[j].length << endl;
                for (int i=0; i<wordList.size(); i++) {
                    ladder thisLadder = result[j];
                    if (!vUsed[i] && differByOne(wordList[i], thisLadder.tail)) {
                        // cout << "differ by one: " << wordList[i] << endl;
                        if (wordList[i] == endWord) return thisLadder.length+1;
                        thisLadder.tail = wordList[i];
                        thisLadder.length++;
                        result.push_back(thisLadder);
                        vUsed[i] = true;
                        used++; // trade space for counting used words
                    }
                }
            }
            if (used == lastUsed) return 0; // prevent dead loop when ladder can't extend
            endOfLastLadder = size; // start checking from this position
        }
        return 0;
    }
private:
    struct ladder {
        string tail;
        int length;
    };
    bool differByOne(const string & v1, const string & v2) {
        int count = 0;
        for (int i=0; i<v1.size(); i++) {
            if (v1[i] != v2[i]) {
                count++;
            }
            if (count > 1) return false;
        }
        if (count == 1) return true;
        if (count == 0) return false; // shouldn't happen
    }
};