//
// Created by gwengww on 8/11/18.
// 4ms 100%
// time O(n)
// space O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size <=1) return size;
        unordered_set<int> hash(nums.begin(), nums.end());
        unordered_set<int>::iterator interval;
        int max_size = 0, this_size = 0;
        int head, tail;
        while (!hash.empty()) {
            this_size = 1;
            interval = hash.begin();
            head = *interval;
            tail = head+1;
            while (hash.find(tail) != hash.end()) {
                hash.erase(tail);
                tail++;
                this_size++;
            }
            while (hash.find(head-1) != hash.end()) {
                hash.erase(head-1);
                head--;
                this_size++;
            }
            max_size = max(max_size, this_size);
            hash.erase(*interval);
        }
        return max_size;
    }
};