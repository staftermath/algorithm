//
// Created by gwengww on 5/1/18.
// beat 95.53%
// space O(N)
// time O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<char> aStack;
        if (s.size() == 0) return true;
        if (s.size()%2==1) return false;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') aStack.push(s[i]);
            else {
                if (aStack.empty()) return false;
                if (s[i] == '}' && aStack.top() == '{' ||
                    s[i] == ']' && aStack.top() == '[' ||
                    s[i] == ')' && aStack.top() == '(') aStack.pop();
                else return false;
            }
        }
        return aStack.empty();
    }
};