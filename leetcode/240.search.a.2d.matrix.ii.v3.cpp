//
// Created by gwengww on 6/10/18.
// beat 81.89%
// 65ms
// time O(m+n)
// space O(1)
// use binary search on vertical value will be much slower averagely, since it will be O(nlogm)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // cout << "===================" << endl;
        if (matrix.size()==0 || matrix[0].size() == 0) return false;
        int col_max = matrix[0].size();
        int row = matrix.size()-1;
        int col = 0;
        while (row >= 0 && col < col_max) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) row--;
            else col++;
        }
        return false;
    }
};