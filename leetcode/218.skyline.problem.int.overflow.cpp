//
// Created by gwengww on 6/23/18.
// overflow on case [[0,2147483647,2147483647]]
// potential huge memory allocation

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        cout << INT_MAX << endl;
        vector<pair<int, int>>  result;
        long right_edge = 0;
        cout << "get right edge" << endl;
        for (int i=0; i<buildings.size(); i++) {
            right_edge = max(right_edge, long(buildings[i][1]));
        }
        right_edge += 2;
        vector<int> height(right_edge--);
        cout << "get height" << endl;
        for (int i=0; i<buildings.size(); i++) {
            for (int j=buildings[i][0]; j<=buildings[i][1]; j++) {
                height[j] = max(height[j], buildings[i][2]);
            }
        }
        long ptr=0;
        cout << "get silhouette" << endl;
        while (ptr < right_edge) {
            if (height[ptr] < height[ptr+1]) result.emplace_back(ptr+1, height[ptr+1]);
            else if (height[ptr] > height[ptr+1]) result.emplace_back(ptr, height[ptr+1]);
            ptr++;
        }

        return result;

    }
};