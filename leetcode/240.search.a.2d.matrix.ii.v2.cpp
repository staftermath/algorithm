//
// Created by gwengww on 6/10/18.
// small improvement.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        if (matrix.back().back() < target || matrix[0][0] > target) return false; // ensure the following calculation make sense
        return searchMatrixDiag(matrix, 0, matrix.size(), 0, matrix[0].size(), target);
    }
    bool searchMatrixDiag(vector<vector<int>>& matrix, int row_start, int row_end, int col_start, int col_end, int target) {
        if (matrix[row_start][col_start] > target || matrix[row_end-1][col_end-1] < target) return false;
        if (row_end-row_start==1) {
            int start = col_start, end=col_end, mid=(start+end)/2;
            while (start+1<end) {
                if (matrix[row_start][mid] == target) return true;
                if (matrix[row_start][mid] > target) end = mid;
                else start = mid;
                mid = (start+end)/2;
            }
            if ( matrix[row_start][start] == target || end!=col_end && matrix[row_start][end] == target) return true;
            return false;
        }

        if (col_end-col_start==1) {
            int start = row_start, end=row_end, mid=(start+end)/2;
            while (start+1<end) {
                if (matrix[mid][col_start] == target) return true;
                if (matrix[mid][col_start] > target) end = mid;
                else start = mid;
                mid = (start+end)/2;
            }
            if  (matrix[start][col_start] == target || end!=row_end && matrix[start][col_start] == target) return true;
            return false;
        }

        int nrow = row_end-row_start, ncol=col_end-col_start;
        int diag = min(nrow, ncol);
        int start = 0, end=diag, mid=(start+end)/2;
        while (start+1<end) {
            if (matrix[mid+row_start][mid+col_start] == target) return true;
            if (matrix[mid+row_start][mid+col_start] > target) end = mid;
            else start = mid;
            mid = (start+end)/2;
        }
        if (matrix[start+row_start][start+col_start] == target ||
            (end+row_start < row_end) && (end+col_start < col_end) && (matrix[end+row_start][end+col_start] == target)) return true;
        if (row_start+end == row_end) return searchMatrixDiag(matrix,
                                                          row_start, row_end,
                                                          col_start+start, col_end, target);
        if (col_start+end == col_end) return searchMatrixDiag(matrix,
                                                          row_start+start, row_end,
                                                          col_start, col_end, target);
        return searchMatrixDiag(matrix, row_start+end, row_end, col_start, col_start+end, target) ||
            searchMatrixDiag(matrix, row_start, row_start+end, col_start+end, col_end, target);

    }
};