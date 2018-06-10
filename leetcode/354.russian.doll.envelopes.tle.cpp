//
// Created by gwengww on 6/9/18.
//

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() <= 1) return envelopes.size();
        int maximum = 1;
        map<int, set<pair<int, int>>> pool;
        for (auto& p: envelopes) {
            pool[p.first+p.second].insert(p);
        }
        // for (auto& p: pool) {
        //     cout << "at level " << p.first << endl;
        //     for (auto& x: p.second) {
        //         cout <<"(" << x.first << "," << x.second << ")," << flush;
        //     }
        //     cout << endl;
        // }
        set<pair<int, int>> dolls;
        dolls.emplace(0,0);
        search_pool(pool, 0, dolls, maximum);
        return maximum-1;
    }

private:
    bool insert_doll(const pair<int, int>& doll, set<pair<int, int>>& dolls) {
        auto iter = dolls.begin();
        while (iter != dolls.end() && doll.first > iter->first && doll.second > iter->second) {
            iter++;
        }

        if (iter == dolls.end() || doll.first < iter->first && doll.second < iter->second && iter != dolls.begin()) {
            // cout << "inserting (" << doll.first << "," << doll.second << ")" << endl;
            dolls.insert(doll);
            return true;
        }
        // cout << "not inserting (" << doll.first << "," << doll.second << ")" << endl;
        return false;
    }
    void search_pool(map<int, set<pair<int, int>>>& pool, int pos, set<pair<int, int>>& dolls, int& maximum) {
        // cout << "now at level " << pos << endl;
        if (pos==int(pool.size())) {
            // cout << "reaching the end. dolls size is " << dolls.size() << endl;
            maximum = max(maximum, int(dolls.size()));
            return;
        }
        auto iter = pool.begin();
        for (int i=0; i < pos; i++) {
            iter++;
        }
        // cout << "iter reaches level " << iter->first << endl;
        for (auto& p: iter->second) {
            // cout <<"checking (" << p.first << "," << p.second << ")," << endl;
            if (insert_doll(p, dolls)) {
                inserted = true;
                search_pool(pool, pos+1, dolls, maximum);
                dolls.erase(p);
            }
        }
        // cout << "nothing inserted, try next level "<< endl;
        search_pool(pool, pos+1, dolls, maximum);

    }
};