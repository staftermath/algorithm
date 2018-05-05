//
// Created by gwengww on 5/4/18.
// 535ms
// very bad. O(N!) complexity?

class Solution {
public:
    int maxArea(vector<int>& height) {
        return helper(height, 0, height.size()-1);
    }
private:
    int helper(vector<int>& height, int start, int end) {
        if (start >= end) return 0;
        if (start + 1 == end) {
            return min(height[start], height[end]);
        }
        int left_low = 0;
        int left_big = 0;
        int tail = end;
        int alter_max = 0;
        while (height[tail] < height[start] && tail >=start+1) {
            alter_max = max(alter_max, height[tail]*(tail-start));
            tail--;

        }
        alter_max = max(alter_max, height[start]*(tail-start));
        return max(alter_max, helper(height, start+1, end));
    }
};