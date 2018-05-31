//
// Created by gwengww on 5/30/18.
// beat 74.08%

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens(n, string(n, '.'));
        vector<vector<string>> result;
        solveNQueens(result, queens, 0, n);
        return result;
    }
private:
    bool is_feasible(vector<string>& queens, int row, int col, int n) {
        for (int i=0; i<row; i++) {
            if (queens[i][col] == 'Q') return false;
        }
        for (int i=1; col-i>=0 && row-i>=0; i++) {
            if (queens[row-i][col-i] == 'Q') return false;
        }
        for (int i=1; col+i<n && row-i >=0; i++) {
            if (queens[row-i][col+i] == 'Q') return false;
        }
        return true;
    }

    void solveNQueens(vector<vector<string>>& result, vector<string>& queens, int row, int n) {
        if (row == n) {
            result.push_back(queens);
        }
        for (int col=0; col<n ; col++) {
            if (is_feasible(queens, row, col, n)) {
                queens[row][col] = 'Q';
                solveNQueens(result, queens, row+1, n);
                queens[row][col] = '.';
            }
        }
    }


};