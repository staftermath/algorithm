//
// Created by gwengww on 8/21/18.
// time O(n*logn)
// space O(n)

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int size = A.size();
        multiset<int> hash(A.begin(), A.end());
        set<int>::iterator p;
        for (int i=0; i<size; i++) {
            p = (*hash.rbegin() <= B[i])? hash.begin(): hash.upper_bound(B[i]);
            A[i] = *p;
            hash.erase(p);
        }
        return A;
    }
};