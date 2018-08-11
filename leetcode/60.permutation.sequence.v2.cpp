//
// Created by gwengww on 8/10/18.
// cleaner
// be careful about the edge case:
// k=1 means it's the first element. so need to do k-- at the beginning.

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> steps(n);
        steps[0] = 1;
        string unused = "123456789";
        for (int i=1;i<n; i++) {
            steps[i] = steps[i-1]*i;
        }
        k--;
        string result = "";
        int pos=n-1;
        int digit;
        while (pos>0) {
            digit = k/steps[pos];
            k = k%steps[pos] ;
            result += unused[digit];
            unused.erase(digit, 1);
            pos--;
        }
        result += unused[0];
        return result;

    }
};