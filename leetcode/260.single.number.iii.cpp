//
// Created by gwengww on 7/28/18.
//

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp;
        temp = accumulate(nums.begin(), nums.end(), 0, [](int x, int y){return x^y;});
        int lastBit = (temp&(temp-1))^temp;
        int groupA=0, groupB=0;
        for (int i=0; i<nums.size(); i++) {
            if (lastBit&nums[i]) groupA^=nums[i];
            else groupB^=nums[i];
        }
        return {groupA, groupB};
    }
};