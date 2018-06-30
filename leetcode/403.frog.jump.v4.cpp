//
// Created by gwengww on 6/30/18.
// 11ms 98.87%
// DFS with truning and hashing
// 

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int size = stones.size();
        if (size <= 1) return true;
        if (stones[1] != 1) return false;
        if (size == 2) return true;
        unordered_map<int, int> hash;
        for (int i=1; i<size; i++) {
            hash[stones[i]] = i;
            if (stones[i] - stones[i-1] > stones[i-1]+1) return false;
        }
        return canCross(stones, hash, 1, 1);
    }

    bool canCross(vector<int>& stones, unordered_map<int, int>& hash, int pos, int last_jump) {
        if (stones.back() - stones[pos] < last_jump-1) return false;
        if (abs(stones.back() - stones[pos] - last_jump ) <= 1) return true;
        if (hash.find(stones[pos]+last_jump+1) != hash.end() && canCross(stones, hash, hash[stones[pos]+last_jump+1], last_jump+1)) return true;
        if (hash.find(stones[pos]+last_jump) != hash.end() && canCross(stones, hash, hash[stones[pos]+last_jump], last_jump)) return true;
        if (last_jump > 1 && hash.find(stones[pos]+last_jump-1) != hash.end() && canCross(stones, hash, hash[stones[pos]+last_jump-1], last_jump-1)) return true;
        else return false;
    }
};