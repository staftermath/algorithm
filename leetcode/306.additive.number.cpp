//
// Created by gwengww on 8/14/18.
// 0ms 100%
// tons of edge cases

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int size = num.size();
        if (size<=2) return false;
        vector<int> num_v(size);
        for (int i=0; i<size; i++) {
            num_v[i] = num[i]-'0';
        }
        for (int i=1; i<=size/2; i++) {
            for (int j=i+1; j<size && j-i<=size/2; j++) {
                if (helper(num_v, 0, i, j, size)) return true;
            }
        }
        return false;
    }

    bool helper(vector<int>& num, int last_start, int this_start, int next_start, const int size) {
        // determine digit to move forward
        if (next_start == size) return true;
        if (next_start > size) return false;
        // cout << "checking a: (" << last_start << "," << this_start << ") b: (" << this_start << "," << next_start << ")" << endl;
        int this_length = next_start-this_start;
        int last_length = this_start-last_start;
        int length = max(this_length, last_length);
        if (num[next_start] == 0 && length >1 || num[this_start] == 0 && this_length>1 || num[last_start]==0 && last_length > 1) return false;
        int next_end;
        if (this_length == last_length+1 && num[this_start] == 9 && num[last_start]+num[this_start+1] > 9 ||
            this_length == last_length && num[last_start]+num[this_start] > 9 ) {
            next_end = next_start+length+1;
            length++;
        } else {
            next_end = next_start+length;
        }

        // cout << "length is " << length << endl;
        if (next_end > size) return false;
        int i=1;
        int add=0;
        int a, b;
        // cout << "next end is " << next_end << endl;
        while (i<=length) {
            a = (this_start-i>=last_start)? num[this_start-i]: 0;
            b = (next_start-i>=this_start)? num[next_start-i]: 0;
            // cout << "a is " << a << " b is " << b << " add is " << add << endl;
            if ((a+b+add)%10 != num[next_end-i]) return false;
            add = (a+b+add)/10;
            i++;
        }
        // cout << "sum found" << endl;
        return helper(num, this_start, next_start, next_end, size);
    }

};