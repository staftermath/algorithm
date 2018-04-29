//
// Created by gwengww on 4/29/18.
// beat 90.63%

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
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        int maximum = 2;
        for (int i=0; i<points.size()-1; i++) {
            map<pair<int, int>, int> hash;
            int duplicate = 1;
            for (int j=i+1; j<points.size(); j++) {
                if (points[j].x==points[i].x && points[j].y==points[i].y) {
                    duplicate++;
                } else {
                    int numerator = points[j].x - points[i].x;
                    int denominator = points[j].y - points[i].y;
                    pair<int, int> slope;
                    if (numerator == 0) {
                        slope = make_pair(0, 1);
                    } else if (denominator == 0) {
                        slope = make_pair(1, 0);
                    } else {
                        int gcd = GCD(numerator, denominator);
                        if (numerator < 0) {
                            numerator = -numerator;
                            denominator = -denominator;
                        }
                        // cout << "GCD: " << gcd << endl;
                        numerator /= gcd;
                        denominator /= gcd;
                        slope = make_pair(numerator, denominator);
                    }
                    // cout << "(" << points[j].x << "," << points[j].y << ")" << " slope " << slope.first << ", " << slope.second << endl;
                    // if (hash.find(slope) != hash.end()) {
                    hash[slope]++;
                    // } else {
                    //     hash[slope] = 1;
                    // }
                }
            }
            int temp = 0;
            for (auto p=hash.begin(); p!=hash.end(); p++) {
                temp = max(temp, p->second);

            }
            // cout << "temp: " << temp << endl;
            // cout << "duplicate: " << duplicate << endl;
            maximum = max(maximum, temp+duplicate);
        }
        return maximum;
    }
private:
    int GCD(int numerator, int denominator) {
        int a = max(numerator, -numerator);
        int b = max(denominator, -denominator);
        while (b > 0) {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
};