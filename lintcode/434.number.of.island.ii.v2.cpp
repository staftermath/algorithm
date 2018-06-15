//
// Created by gwengww on 6/14/18.
// 1005ms 67.80%
//

/**
 * Definition for a point.
 * struct Point {
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
        vector<int> islands(n*m);
        for (int i=0; i<n*m; i++) {
            islands[i] = i;
        }
        vector<vector<int>> sea(n, vector<int>(m));
        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};
        int island_num = 0;
        vector<int> result;
        for (auto & p: operators) {
            // cout << "operating on " << operators[o].x << "," << operators[o].y << endl;
            if (sea[p.x][p.y] != 1) {
                island_num++;
                sea[p.x][p.y] = 1;
                int f = p.x*m+p.y;
                int x, y;
                for (auto& move: moves) {
                    x = p.x+move.first;
                    y = p.y+move.second;
                    if ( x>=0 && x<n &&  y>=0 && y<m && sea[x][y] == 1 && findParent(islands, x*m+y) != f) {
                        islands[findParent(islands, x*m+y)] = f;
                        island_num--;
                    }
                }
            }
            result.push_back(island_num);
        }
        return result;

    }

    int findParent(vector<int>& islands, int pos) {
        if (islands[pos] == pos) return pos;
        islands[pos] = findParent(islands, islands[pos]);
        return islands[pos];
    }
};