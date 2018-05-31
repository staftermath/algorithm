//
// Created by gwengww on 5/29/18.
//
// TLE

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) return {{"Q"}};
        if (n == 2 || n <= 0) return {};
        vector<pair<int, int>> candidates;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                candidates.push_back(make_pair(i,j));
            }
        }
        vector<vector<pair<int, int>>> result;
        unordered_set<int> rows = {};
        unordered_set<int> cols = {};
        unordered_set<int> diag = {};
        unordered_set<int> off_diag = {};
        for (int i=0; i< candidates.size(); i++) {
            // cout << "starting candidates: " << candidates[i].first << "," << candidates[i].second << endl;
            // cout << "rows before: " << flush;
            // for (auto& k: rows) {
            //     cout << k << ","<< flush;
            // }
            // cout << endl;
            auto remainings = create_candidates(i, candidates, rows, cols, diag, off_diag, n-1);
            // cout << "rows after: " << flush;
            // for (auto& k: rows) {
            //     cout << k << ","<< flush;
            // }
            // cout << endl;
            for (auto& remaining: remainings) {
                remaining.push_back(candidates[i]);
                result.push_back(remaining);
            }
        }
        // for (auto& v: result) {
        //     for (auto&p : v) {
        //         cout << p.first << ", " << p.second << endl;
        //     }
        // }
        return print(result, n);
    }
private:
    vector<vector<string>> print(vector<vector<pair<int, int>>> solutions, int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        for (auto& solution: solutions) {
            vector<string> newBoard(board);
            for (auto& queen: solution) {
                newBoard[queen.first][queen.second] = 'Q';
            }
            result.push_back(newBoard);
        }
        return result;
    }
    bool is_feasible(pair<int, int>& node, unordered_set<int> rows, unordered_set<int> cols, unordered_set<int> diag, unordered_set<int> off_diag) {
        return rows.find(node.first) == rows.end()
               && cols.find(node.second) == cols.end()
               && diag.find(node.second - node.first) == diag.end()
               && off_diag.find(node.second + node.first) == off_diag.end();
    }

    vector<vector<pair<int, int>>> create_candidates(int position, vector<pair<int, int>>& candidates, unordered_set<int>& rows, unordered_set<int>& cols, unordered_set<int>& diag, unordered_set<int>& off_diag, int remaining_depth) {
        if (remaining_depth == 0) {
            // cout << "found it: " << candidates[position].first << "," << candidates[position].second << endl;
            return {{candidates[position]}};
        }
        vector<vector<pair<int, int>>> result;
        // cout << "(depth: " << remaining_depth << ") target: " << candidates[position].first << "," << candidates[position].second << endl;
        // for (int k=position+1; k<candidates.size(); k++) {
        //     cout << "candidates: " << candidates[k].first << "," << candidates[k].second << endl;
        // }
        vector<pair<int, int>> new_candidates;
        rows.insert(candidates[position].first);
        cols.insert(candidates[position].second);
        diag.insert(candidates[position].second-candidates[position].first);
        off_diag.insert(candidates[position].second+candidates[position].first);
        for (int k=position+1; k<candidates.size(); k++) {
            if (is_feasible(candidates[k], rows, cols, diag, off_diag)) {
                // cout << "feasible: " << candidates[k].first << "," << candidates[k].second << endl;
                new_candidates.push_back(candidates[k]);
            }
        }
        if (new_candidates.size() == 0) {
            rows.erase(candidates[position].first);
            cols.erase(candidates[position].second);
            diag.erase(candidates[position].second-candidates[position].first);
            off_diag.erase(candidates[position].second+candidates[position].first);
            return {};
        }
        for (int i=0; i<new_candidates.size(); i++) {
            auto remainings = create_candidates(i, new_candidates, rows, cols, diag, off_diag, remaining_depth-1);
            for (auto& remaining: remainings) {
                remaining.push_back(candidates[position]);
                result.push_back(remaining);
            }
        }
        rows.erase(candidates[position].first);
        cols.erase(candidates[position].second);
        diag.erase(candidates[position].second-candidates[position].first);
        off_diag.erase(candidates[position].second+candidates[position].first);
        return result;
    }
};