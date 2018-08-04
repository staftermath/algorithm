//
// Created by gwengww on 8/2/18.
//

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int i=0;
        while (a[i] != '+') i++;
        Complex c1(stoi(a.substr(0, i)), stoi(a.substr(i+1, a.size()-i-2)));
        i=0;
        while (b[i] != '+') i++;
        Complex c2(stoi(b.substr(0, i)), stoi(b.substr(i+1, b.size()-i-2)));
        return (c1*c2).toString();
    }

    struct Complex {
        int a;
        int b;
        Complex() {};
        Complex(int x, int y): a(x), b(y) {};

        Complex operator*(const Complex& c) {
            Complex result;
            result.a = this->a*c.a - this->b*c.b;
            result.b = this->a*c.b + this->b*c.a;
            return result;
        }

        string toString() {
            return to_string(this->a) + "+" + to_string(this->b) + "i";
        }
    };
};