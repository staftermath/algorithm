//
// Created by gwengww on 9/17/18.
// 0ms 100%
// dfs to find the node. bfs to find the final nodes with distance K

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> s;
        if (!dfs(root, target, s)) return {};
        queue<TreeNode*> s_d; // stack of nodes with distance  == 0;
        int distance = 1; // start looking for distance == 0 nodes
        s_d.push(s.back());
        TreeNode* node;
        TreeNode* last_node = nullptr;
        int last_pos = s.size()-1;
        while (distance <= K) {
            int s_d_size = s_d.size();

            while (s_d_size > 0) {
                // look down
                node = s_d.front();
                s_d.pop();
                if (node->left != nullptr && node->left != last_node) {
                    s_d.push(node->left);
                }
                if (node->right != nullptr && node->right != last_node) {
                    s_d.push(node->right);
                }
                s_d_size--;
            }
            if (last_pos > 0) {
                // look up
                last_node = s[last_pos];
                last_pos--;
                s_d.push(s[last_pos]);
            }
            distance++;
        }
        vector<int> result;
        while (!s_d.empty()) {
            result.emplace_back(s_d.front()->val);
            s_d.pop();
        }
        return result;
    }

    bool dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& s) {
        if (node == target) {
            s.push_back(node);
            return true;
        } else {
            if (node == nullptr || node->left == nullptr && node->right == nullptr) return false;
            s.push_back(node);
            if (node->left != nullptr && dfs(node->left, target, s)) return true;
            if (node->right != nullptr && dfs(node->right, target, s)) return true;
            s.pop_back();
            return false;
        }
    }
};