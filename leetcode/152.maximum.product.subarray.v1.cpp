//
// Created by gwengww on 9/24/18.
// 4ms 98.57%
// time O(n)
// space O(1)
// ugly ass code

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        int maximum = nums[0];
        int current_product = 1;
        int i=0;
        int start_pos = -1;
        while (i<size) {
            maximum = max(maximum, nums[i]);
            if (nums[i] != 0) {
                current_product*=nums[i];
                maximum = max(maximum, current_product);
                i++;
            } else {
                start_pos++;
                while (start_pos < i-1) {
                    // cout << "dividing " << start_pos << ": " << nums[start_pos] << endl;
                    current_product /= nums[start_pos];
                    if (nums[start_pos] < 0) break;
                    start_pos++;
                }
                if (i>0 && nums[i-1]) {
                    maximum = max(maximum, current_product);
                }
                current_product = 1;
                start_pos = i;
                i++;
            }
        }
        start_pos++;
        while (start_pos < i-2) {
            // cout << "dividing " << start_pos << ": " << nums[start_pos] << endl;
            current_product/=nums[start_pos];
            if (nums[start_pos] < 0) break;
            start_pos++;
        }
        if (nums.back() != 0) {
            maximum = max(maximum, current_product);
        }
        return maximum;
    }
};