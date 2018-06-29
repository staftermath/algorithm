//
// Created by gwengww on 6/23/18.
//

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        vector<pair<int, int>>  result;
        vector<pair<int, int>> right_edge;
        sort(buildings.begin(), buildings.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[0] < b[0])? true: a[0]==b[0] && a[2]>b[2];
        });
        result.emplace_back(buildings[0][0],buildings[0][2]);
        if (buildings.size() == 1) {
            result.emplace_back(buildings[0][1], 0);
            return result;
        }
        right_edge.emplace_back(buildings[0][1], buildings[0][2]);
        int next_building = 1, ptr=0, current_height = buildings[0][2];
        while (true) {
            // for (auto& p: right_edge) {
            //     cout << "(" << p.first << "," << p.second << ")," << flush;
            // }
            // cout << endl;
            if (next_building < buildings.size() && !right_edge.empty()) {
                // cout << "case 1" << endl;
                if (buildings[next_building][0] < right_edge.begin()->first) {
                    // looking at next building
                    if (buildings[next_building][2] > current_height) {
                        // next building is taller
                        current_height = buildings[next_building][2];
                        // cout << "inserting " << buildings[next_building][0] << "," << buildings[next_building][2] << endl;
                        result.emplace_back(buildings[next_building][0], buildings[next_building][2]);
                    }
                    construct_right_edge(right_edge, buildings[next_building][1], buildings[next_building][2]);
                    next_building++;
                } else if (buildings[next_building][0] == right_edge.begin()->first){
                    if (buildings[next_building][2] >= right_edge.begin()->second) {
                        current_height = buildings[next_building][2];
                        // cout << "inserting " << buildings[next_building][0] << "," << buildings[next_building][2] << endl;
                        if (buildings[next_building][2] == right_edge.begin()->second) {
                            result.emplace_back(buildings[next_building][0], buildings[next_building][2]);
                        }
                    }
                    right_edge.erase(right_edge.begin());
                    construct_right_edge(right_edge, buildings[next_building][1], buildings[next_building][2]);
                    next_building++;
                } else {
                    // reaching right edge
                    insert_from_hash(right_edge, result);
                }
            } else if (!right_edge.empty()) {
                // cout << "case empty hash" << endl;
                insert_from_hash(right_edge, result);
            } else if (next_building < buildings.size()) {
                // cout << "case ran out of building" << endl;
                right_edge.emplace_back(buildings[next_building][1], buildings[next_building][2]);
                current_height = buildings[next_building][2];
                result.emplace_back(buildings[next_building][0], buildings[next_building][2]);
                next_building++;
            } else break;
        }
        return result;

    }

    void construct_right_edge(vector<pair<int, int>>& hash, int edge, int height) {
        // cout << "inserting " << edge << "," << height << endl;
        if (hash.empty()) {hash.emplace_back(edge, height);return;}
        int i=0;
        for (;i<hash.size();) {
            if (hash[i].second > height) i++;
            else if (hash[i].first <= edge) {
                // cout << "erasing " << hash[i].first << "," << hash[i].second << endl;
                hash.erase(hash.begin()+i);
                // cout << "successfuly erased" << endl;
            }
            else {hash.emplace(hash.begin()+i, edge, height); return;}
        }
        if (hash.empty() || hash[i-1].first < edge) hash.emplace_back(edge, height);
    }

    void insert_from_hash(vector<pair<int, int>>& hash, vector<pair<int, int>>& result) {
        int ptr = hash.begin()->first;
        hash.erase(hash.begin());
        if (hash.empty()) result.emplace_back(ptr, 0);
        else {
            // cout << "inserting " << ptr << "," << hash.begin()->second << endl;
            result.emplace_back(ptr, hash.begin()->second);
        }
    }
};