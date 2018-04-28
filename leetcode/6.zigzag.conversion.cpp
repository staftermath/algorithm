//
// Created by gwengww on 4/27/18.
//

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows ==1 ) return s;
        vector<int> result = {};
        int twiceRow = 2*(numRows-1);
        int iter = (s.size()-1)/twiceRow;
        int lastZig = (iter+1)*twiceRow;
        for (int i=0; i<=iter; i++) {
           result.push_back(i*twiceRow);
        }
        
        for (int r=1; r<numRows-1; r++) {
            
            for (int i=0; i<=iter; i++) {
                int anchor = i*twiceRow;
                if (i == 0) {
                    check_push(result, r, s.size());
                } else if (i == iter) {
                    result.push_back(anchor-r);
                    check_push(result, anchor+r, s.size());
                } else {
                    result.push_back(anchor-r);
                    result.push_back(anchor+r);
                }
            }
            int tail = lastZig-r;
            check_push(result, tail, s.size());
        }
        for (int i=0; i<iter; i++) {
            result.push_back(i*twiceRow + numRows - 1);
        }
        
        check_push(result, iter*twiceRow+numRows-1, s.size());
        string resultStr(s);
        for (int i=0; i<s.size(); i++) {
            resultStr[i] = s[result[i]];
        }
        return resultStr;
    }
private:
    void check_push(vector<int> & storage, int index, int maximum) {
        if (index < maximum) {
            storage.push_back(index);
        }
    }
};