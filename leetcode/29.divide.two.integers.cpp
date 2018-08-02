//
// Created by gwengww on 8/1/18.
// 12ms 96.62%
// handle edge cases
// no long int needed

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == INT_MIN) return (dividend == INT_MIN)? 1: 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int quotient = 0;
        int multiple = 0;
        bool changeSign = false;
        if (divisor < 0) {
            changeSign = !changeSign;
            divisor = -divisor;
        }
        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            quotient++;
            dividend += divisor;
        }
        if (dividend < 0) {
            changeSign = !changeSign;
            dividend = -dividend;
        }
        while (dividend >> multiple >= divisor) multiple++;
        multiple--;
        while (multiple>=0) {
            if (dividend >> multiple >= divisor) {
                dividend -= divisor<<multiple;
                quotient += 1<<multiple;
            }
            multiple--;
        }
        return (changeSign)? -quotient: quotient;
    }
};