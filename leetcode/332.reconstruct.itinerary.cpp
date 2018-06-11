//
// Created by gwengww on 6/10/18.
// 16ms 90.61%

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> hash;
        int count=1;
        for (auto& p: tickets) {
            hash[p.first][p.second]++;
            count++;
        }
        vector<string> itinerary;
        string stop = "JFK";
        findItinerary(hash, stop, itinerary, count);
        return itinerary;
    }
private:
    bool findItinerary(unordered_map<string, map<string, int>>& hash, string stop, vector<string>& itinerary, int& count) {
        // cout << "current itinerary: " << flush;
        // for (auto& str: itinerary) {
        //     cout << str << "->" << flush;
        // }
        // cout << endl;
        // cout << "pushing in " << stop << endl;
        itinerary.push_back(stop);
        count--;
        auto search = hash.find(stop);
        if (search == hash.end()) {
            if (count == 0) return true;
            count++;
            itinerary.pop_back();
            return false;
        }
        for (auto iter=search->second.begin(); iter!=search->second.end(); iter++) {
            if (iter->second > 0) {
                iter->second--;
                if (findItinerary(hash, iter->first, itinerary, count)) return true;
                iter->second++;
            }
        }
        if (count==0) return true;
        else {
            count++;
            itinerary.pop_back();
            return false;
        }
    }
};