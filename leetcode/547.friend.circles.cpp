//
// Created by gwengww on 5/8/18.
// beat 84.93%
// time complexity O(N);
// space complexity O(N);


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int circle = 0;
        int SIZE = M.size();
        if (SIZE <= 1) return SIZE;
        unordered_set<int> hash;
        for (int i=0; i<SIZE; i++) {
            hash.insert(i);
        }
        stack<int> pStack;
        while (!hash.empty()) {
            pStack.push(*hash.begin());
            hash.erase(hash.begin());
            while (!pStack.empty() && !hash.empty()) {
                int thisOne = pStack.top();
                pStack.pop();
                unordered_set<int> cache = {};
                for (auto p=hash.begin(); p!=hash.end(); p++) {
                    if (M[thisOne][*p] == 1) {
                        cache.insert(*p); // cache friends of thisOne
                    }
                }
                for (auto p: cache) {
                    hash.erase(p); // remove people who just got added to circle
                    pStack.push(p); // add this people to the circle
                }
            }
            circle++;
        }
        return circle;
    }
};