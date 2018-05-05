//
// Created by gwengww on 5/4/18.
// beat 96.59%   19ms
// time complexity O(N)
// space complexity O(1);

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maximum = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                maximum = max(maximum, height[left]*(right-left));
                int tmp = left+1;
                while (height[tmp] <= height[left]) {
                    tmp++;
                }
                left = tmp;
                continue;
            } else {
                maximum = max(maximum, height[right]*(right-left));
                int tmp = right-1;
                while (height[tmp] <= height[right]) {
                    tmp--;
                }
                right = tmp;
            }
        }
        return maximum;
    }
};