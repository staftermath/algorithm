//
// Created by gwengww on 5/5/18.
// beat 70.92%
// time complexity O(N)
// space complexity O(N)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        if (tokens.size() == 1) return stoi(tokens[0]);
        for (int i=0; i<tokens.size(); i++) {
            if (!isOperation(tokens[i])) numStack.push(stoi(tokens[i]));
            else {
                int b = numStack.top();
                numStack.pop();
                int a = numStack.top();
                numStack.pop();
                int result = operation(a, b, tokens[i]);
                numStack.push(result);
            }
        }
        return numStack.top();
    }
private:
    int operation(int na, int nb, string op) {
        if (op == "+") return na+nb;
        if (op == "-") return na-nb;
        if (op == "/") return na/nb;
        if (op == "*") return na*nb;
    }
    bool isOperation(string s){
        if (s == "+" || s == "-" || s == "/" || s == "*") return true;
        else return false;
    }
};