//
// Created by gwengww on 6/4/18.
// use priority_queue
// beat 78.14%
// If use if else condition in findMedian() only beat 54.20%

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return (small.size() > large.size())? small.top(): (small.top()-large.top())/2.0;
    }
private:
    priority_queue<int> small;
    priority_queue<int> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */