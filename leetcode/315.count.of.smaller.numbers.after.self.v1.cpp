//
// Created by gwengww on 6/16/18.
// 251ms 17.44%

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        if (nums.size() <= 1) return result;
        int start, end, mid, tmp;
        for (int i=size-2; i>=0; i--) {
            start = i+1; end=size; mid=(start+end)/2;
            while (start+1<end) {
                if (nums[mid] < nums[i]) end=mid;
                else start=mid;
                mid = (start+end)/2;
            }
            if (nums[start] < nums[i]) {
                result[i] = size-start;
                end = start;
            }
            else if (end < size) {
                result[i] = size-end;
            }
            tmp = nums[i];
            for (int j=i; j<end-1; j++) {
                nums[j] = nums[j+1];
            }
            nums[end-1] = tmp;

        }
        return result;
    }

};