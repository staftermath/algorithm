//
// Created by gwengww on 8/21/18.
// 132ms 43.02%
// time O(n*n)
// space O(1)

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int size = A.size();
        sort(A.begin(), A.end());
        vector<int> result(size, -1);
        vector<int>::iterator start, end, mid;
        for (int i=0; i<size; i++) {
            start=A.begin();
            end=A.end();
            mid=start+distance(start, end)/2;
            while (start+1<end) {
                if (*mid>B[i]) end = mid;
                else start = mid;
                mid = start+(end-start)/2;
            }
            if (*start > B[i]) {
                result[i] = *start;
                A.erase(start);
            } else if (end != A.end()) {
                result[i] = *end;
                A.erase(end);
            }
        }
        for (int i=0; i<size; i++) {
            if (result[i] == -1) {
                result[i] = *A.begin();
                A.erase(A.begin());
            }
        }
        return result;
    }
};