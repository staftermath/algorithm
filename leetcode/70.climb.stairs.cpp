//
// Created by gwengww on 5/5/18.
// don't use vector to store all history values. take too much space.

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        int a=1, b=2, c;
        for (int i=3; i<=n; i++) {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};