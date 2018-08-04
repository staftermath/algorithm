//
// Created by gwengww on 8/3/18.
//

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator==0) return "0";
        long lnum = numerator;
        long ldenom = denominator;
        if (lnum%ldenom==0) return to_string(lnum/ldenom);

        bool negative = false;
        if (lnum<0) {
            negative = !negative;
            lnum = -lnum;
        }
        if (ldenom<0) {
            negative = !negative;
            ldenom = -ldenom;
        }
        string result = to_string(lnum/ldenom)+".";
        vector<string> decimal;
        lnum%=ldenom;
        long gcd = getGCD(lnum, ldenom);
        // cout << "GCD:"<< gcd <<endl;
        lnum /= gcd;
        ldenom /= gcd;
        unordered_map<long, long> hash;
        long quotient, position=0;
        while (ldenom%10 == 0) {
            ldenom /= 10;
            quotient = lnum/ldenom;
            lnum %= ldenom;
            result += to_string(quotient);
        }
        while (hash.find(lnum) == hash.end() && lnum != 0) {
            hash[lnum] = position++;
            lnum*=10;
            pointer=0;
            while (lnum<ldenom) {
                hash[lnum] = position++;
                lnum*=10;
                decimal.emplace_back("0");
            }
            quotient = lnum/ldenom;
            lnum %= ldenom;
            decimal.emplace_back(to_string(quotient));
        }
        if (lnum != 0) {
            decimal.insert(decimal.begin()+hash[lnum], "(");
            decimal.emplace_back(")");
        }
        result = accumulate(decimal.begin(), decimal.end(), result);
        return (negative)? "-"+result:result;


    }

    long getGCD(long numerator, long denominator) {
        long quotient = numerator/denominator, remainder = numerator%denominator;
        while (remainder!=0) {
            numerator = denominator;
            denominator = remainder;
            quotient = numerator/denominator;
            remainder = numerator%denominator;
        }
        return denominator;
    }
};