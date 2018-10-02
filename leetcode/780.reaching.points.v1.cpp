//
// Created by gwengww on 10/1/18.
// 4ms 50%
// there is a better solution

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy) {
            (tx > ty)? tx = tx-ty: ty = ty-tx;
        }
        if (tx == sx && ty == sy) return true;
        if (tx == sx && ty > sy) return (ty-sy)%sx == 0;
        if (ty == sy && tx > sx) return (tx-sx)%sy == 0;
        return false;
    }
};