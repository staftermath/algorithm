class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        for (int i=edges.size()-1; i >=0; i--) {
            int badEdgeIndex = isLegit(edges, i);
            if (badEdgeIndex == -1) return edges[i];
        }
        
    }
private:
    struct position{
      unordered_map<int, bool> headOf;
      bool isTail;
    };
    
    bool findTail(int head, int tail, unordered_map<int, position> hash) {
        bool result = false;
        auto headSearch = hash.find(tail);
        if (headSearch == hash.end()) return false;
        auto headOf = headSearch->second.headOf;
        for (auto val: headOf) {
            if (val.first == head) return true;
            result = result || findTail(head, val.first, hash);
        }
        return result;
    }
    
    int isLegit(vector<vector<int>> &edges, int skip) {
        unordered_map<int, position> hash = {};
        for (int i=0; i < edges.size(); i++) {
            if (i == skip) continue;
            auto v = edges[i];
            auto headSearch = hash.find(v[0]);
            if (headSearch != hash.end()) {
                hash[v[0]].headOf[v[1]] = true; // value doesn't matter
            } else {
                hash[v[0]] = {unordered_map<int, bool>{{v[1], true}}, false};
            }
            auto tailsearch = hash.find(v[1]);
            if (tailsearch!= hash.end()) {
                if (tailsearch->second.isTail) return i;
                tailsearch->second.isTail = true;
                bool isTail = findTail(v[0], v[1], hash);
                if (isTail) return i;
            } else {
                hash[v[1]] = {unordered_map<int, bool>{}, true};
            }
        }
        return -1;
    }
};
