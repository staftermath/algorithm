//
// Created by gwengww on 6/9/18.
//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        for (int i=0; i<matrix[0].size(); i++) {
            int start = 0, end = matrix.size(), mid = (start+end)/2;
            while (start + 1 < end) {
                if (matrix[mid][i] == target) return true;
                else if (matrix[mid][i] > target) end = mid;
                else if (matrix[mid][i] < target) start = mid;
                mid = (start+end)/2;
            }
            
            if (matrix[start][i] == target || (end < matrix.size() && matrix[end][i] == target)) return true;
            
        }
        return false;
    }
};