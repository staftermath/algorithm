//
// Created by gwengww on 6/9/18.
// leetcode 149 beat 77.22%
// beat 46.00%
// use unordered_map<int, unordered_map<int, int>> to beat 64%

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
     * @param points: an array of point
     * @return: An integer
     */
    int maxPoints(vector<Point> &points) {
        // write your code here
        if (points.size() <= 2) return points.size();
        int max_length = 2;
        for (int i=0; i<points.size(); i++) {
            // cout << "== new origin (" << points[i].x << ", " << points[i].y <<  ") == " << endl;
            map<pair<int, int>, int> hash;
            int pre = 1;

            for (int j=i+1; j<points.size();j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    pre++;
                    continue;
                }
                pair<int, int> slope = find_slope(points[j], points[i]);
                // cout << "slope of " << "("<< points[j].x << "," << points[j].y << ") to ("
                // << points[i].x << "," << points[i].y << ") is " << slope.first << ", " << slope.second << endl;
                hash[slope]++;
            }
            int length = 0;
            for (auto& slope: hash) {
                length = max(slope.second, length);
            }
            max_length = max(pre+length, max_length);
        }
        return max_length;
    }
private:
    pair<int, int> find_slope(Point& a, Point& b) {
        int x = b.x-a.x, y = b.y - a.y, tmp_x=abs(x), tmp_y=abs(y);
        if (x == 0) return make_pair<int, int>(0, 1);
        if (y == 0) return make_pair<int, int>(1, 0);
        int remainder = tmp_x%tmp_y;
        while (remainder != 0) {
            tmp_x = tmp_y;
            tmp_y = remainder;
            remainder = tmp_x%tmp_y;
        }
        return (y>0)? make_pair<int, int>(x/tmp_y, y/tmp_y): make_pair<int, int>(-x/tmp_y, -y/tmp_y);

    }
};