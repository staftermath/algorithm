//
// Created by gwengww on 6/13/18.
// 2326ms 10.60%

/**
 * Definition for a point.
 * struct Point {1
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        unordered_map<int, vector<Point>> islands;
        vector<vector<int>> sea(n, vector<int>(m));
        vector<int> neighbors(4);
        vector<int> result(operators.size());
        int island_num = 1;
        for (int o=0; o<operators.size(); o++) {
            if (sea[operators[o].x][operators[o].y] == 0){
                // cout << "operating on " << operators[o].x << "," << operators[o].y << endl;
                neighbors[0] = getIslandNumber(sea, operators[o].x-1, operators[o].y, n, m); // left
                neighbors[1] = getIslandNumber(sea, operators[o].x+1, operators[o].y, n, m); // right
                neighbors[2] = getIslandNumber(sea, operators[o].x, operators[o].y-1, n, m); // up
                neighbors[3] = getIslandNumber(sea, operators[o].x, operators[o].y+1, n, m); // down
                int change = 0;
                for (int i=0; i<4; i++) {
                    if (neighbors[i] != 0) {
                        if (change == 0) {
                            change = neighbors[i];
                            sea[operators[o].x][operators[o].y] = change;
                            islands[change].push_back(operators[o]);
                        } else if (change != neighbors[i]) {
                            islands[change].insert(islands[change].end(), islands[neighbors[i]].begin(), islands[neighbors[i]].end());
                            for (auto& isle: islands[neighbors[i]]) {
                                sea[isle.x][isle.y] = change;
                            }
                            islands.erase(neighbors[i]);
                        }
                    }
                }
                if (change == 0) {
                    sea[operators[o].x][operators[o].y] = island_num;
                    islands[island_num].push_back(operators[o]);
                    island_num++;
                }
            }
            result[o] = islands.size();
        }
        return result;

    }

    int getIslandNumber(vector<vector<int>>& sea, int x, int y, int n, int m) {
        return (x<0 || x>=n || y<0 || y>=m)? 0: sea[x][y];
    }
};