//
// Created by gwengww on 6/9/18.
// beat 54.35%
// time O(logN)
// space O(logN)

class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> &points) {
        // Write your code here
        if (points.size()<=1) return true;
        unordered_map<int, unordered_set<int>> hashMap;
        int min_x = points[0][0], max_x = points[0][0];
        for (int i=0; i<points.size(); i++) {
            max_x = max(max_x, points[i][0]);
            min_x = min(min_x, points[i][0]);
            hashMap[points[i][0]].insert(points[i][1]);
        }
        int double_y = max_x+min_x;
        for (auto& p: hashMap) {
            int reflect = double_y-p.first;
            auto search = hashMap.find(reflect);
            if (search == hashMap.end()) return false;
            for (auto& inner: p.second) {
                if ( search->second.find(inner) == search->second.end()) return false;
            }
        }
        return true;
    }
};