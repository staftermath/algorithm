//
// Created by gwengww on 6/5/18.
// beat 94.64%
// if use set<string> for searched, it will be much slower.

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> dict;
        for (int i=0; i< equations.size(); i++) {
            dict[equations[i].first][equations[i].second] = values[i];
            if (values[i] != 0) dict[equations[i].second][equations[i].first] = 1/values[i];
        }
        vector<double> result(queries.size());
        for (int i=0; i< queries.size(); i++) {
            unordered_set<string> searched;
            result[i] = search(queries[i].first, queries[i].second, dict, searched);
        }
        return result;
    }
private:
    double search(string num, string denom, unordered_map<string, unordered_map<string, double>>& dict, unordered_set<string>& searched) {
        auto p = dict[num];
        if (p.find(denom) != p.end()) return p[denom];
        for (auto& denoms: p) {
            double result = denoms.second;
            if (searched.find(denoms.first) == searched.end()) {
                searched.insert(denoms.first);
                double tmp = search(denoms.first, denom, dict, searched);
                if (tmp != -1.0) return result*tmp;
            }
        }
        return -1.0;
    }
};