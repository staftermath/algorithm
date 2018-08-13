//
// Created by gwengww on 8/12/18.
// 40ms 73.05%
// dfs

class Solution {
public:
    int countArrangement(int N) {
        unordered_set<int> hash;
        unordered_map<int, set<int>> divisor;
        for (int i=1; i<=N ; i++) {
            hash.insert(i);
            int k=1;
            while (k*i<=N) {
                divisor[i].insert(k*i);
                divisor[k*i].insert(i);
                k++;
            }
        }
        int count = 0;
        helper(hash, divisor, N, count);
        return count;
    }

    void helper( unordered_set<int>& hash, unordered_map<int, set<int>>& divisor, int i, int& count) {
        if (i==0) {
            count++;
            return;
        }
        for (auto p: divisor[i]) {
            if (hash.find(p)!=hash.end()) {
                hash.erase(p);
                helper(hash, divisor, i-1, count);
                hash.insert(p);
            }
        }
        return;
    }
};