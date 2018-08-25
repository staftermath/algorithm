//
// Created by gwengww on 8/24/18.
// 20ms 50.77%
// BFS
// time O(n)
// space O(n)

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        unordered_map<int, UndirectedGraphNode*> hash;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode* current;
        while (!q.empty()) {
            current = q.front();
            q.pop();
            if (hash.find(current->label) == hash.end()) {
                hash[current->label] = new UndirectedGraphNode(current->label);
            }
            insertNeighbor(current, hash[current->label], hash, q);
        }
        return hash[node->label];
    }
    void insertNeighbor(UndirectedGraphNode *from, UndirectedGraphNode *to, unordered_map<int, UndirectedGraphNode*> & hash, queue<UndirectedGraphNode*> & q) {
        for (auto n: from->neighbors) {
            if (hash.find(n->label) == hash.end()) {
                hash[n->label] = new UndirectedGraphNode(n->label);
                q.push(n);
            }
            to->neighbors.push_back(hash[n->label]);
        }
    }
};