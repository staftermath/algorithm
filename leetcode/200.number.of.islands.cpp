//
// Created by gwengww on 6/13/18.
// 14ms 93.82%
// time O(mn)
// space O(1)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        int island = 0;
        for (int i=0; i<m ; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    findIslands(grid, i, j, m, n);
                    island++;
                }
            }
        }
        return island;
    }

    void findIslands(vector<vector<char>>& grid, const int x, const int y, const int m, const int n) {
        if (x < 0 || x >=m || y < 0 || y >= n || grid[x][y] == '0' || grid[x][y] == 's') return;
        grid[x][y] = 's';
        findIslands(grid, x+1, y, m, n);
        findIslands(grid, x-1, y, m, n);
        findIslands(grid, x, y-1, m, n);
        findIslands(grid, x, y+1, m, n);
        return;

    }
};