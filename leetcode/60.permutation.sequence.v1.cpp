//
// Created by gwengww on 8/10/18.
// 4m 67.64%
// time O(n)
// space O(n)

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> steps(n);
        steps[0] = 1;
        vector<int> unused(n);
        unused[0] = 1;
        // cout << steps[0] << "," << flush;
        for (int i=1;i<n; i++) {
            unused[i]=i+1;
            steps[i] = steps[i-1]*i;
            // cout << steps[i] << "," << flush;
        }
        cout << endl;
        string result = "";
        int pos=n-1;
        vector<int>::iterator digit;
        while (pos>0) {
            digit = unused.begin();
            while (k>steps[pos]) {
                k -= steps[pos];
                digit++;
            }
            result += to_string(*digit);
            unused.erase(digit);
            pos--;
        }
        result += to_string(*unused.begin());
        return result;

    }
};