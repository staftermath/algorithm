//
// Created by gwengww on 9/30/18.
// TLE
// time O(n*n)
// space O(n)

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int size = A.size();
        if (size<=1) return 0;
        sort(A.begin(), A.end());
        int module = 1000000000+7;
        vector<long> powers(size, 1);
        for (int i=1; i<size; i++) {
            powers[i] = (powers[i-1]*2)%module;
        }
        long result = 0;
        for (int i=0; i<size; i++) {
            for (int j=1; j+i<size; j++) {
                result += (powers[j-1]*(A[j+i]-A[i]))%module;
                result = result % module;
            }
        }
        return result;
    }
};