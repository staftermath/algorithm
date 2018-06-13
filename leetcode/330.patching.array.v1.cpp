//
// Created by gwengww on 6/11/18.
// 10ms 22.98%
// 8ms 85.11% if use comments

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int p = 0;
        int patches = 0;
        long limit = 0;
        while (limit < n) {
            if (p<nums.size()) {
                if (nums[p] > limit+1) {
                    patches++;
                    limit += limit+1; // limit <<= 1; limit++;
                } else {
                    limit += nums[p];
                    p++;
                }
            } else {
                patches++;
                limit += limit + 1; // limit <<= 1; limit++;
            }
        }

        return patches;
    }
};

//class Solution {
//public:
//    int minPatches(vector<int>& nums, int n) {
//        int p = 0;
//        int patches = 0;
//        int size = nums.size();
//        long limit = 0;
//        while (limit < n) {
//            if (p < size && nums[p] <= limit +1) {
//                limit +=nums[p++];
//            }
//            else {
//                patches++;
//                limit <<= 1;
//                limit++;
//            }
//        }
//        return patches;
//    }
//};