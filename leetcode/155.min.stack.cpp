//
// Created by gwengww on 5/5/18.
// beat 79.71%

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        pStack.push(x);
        if (pMinStack.empty()) pMinStack.push(x);
        else pMinStack.push(min(pMinStack.top(), x));
    }

    void pop() {
        pStack.pop();
        pMinStack.pop();
    }

    int top() {
        return pStack.top();
    }

    int getMin() {
        return pMinStack.top();
    }
private:
    stack<int> pStack;
    stack<int> pMinStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */