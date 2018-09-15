//
// Created by gwengww on 9/15/18.
// 12ms 99.90%
// BFS

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1) {
            TreeNode* result = new TreeNode(v);
            result->left = root;
            return result;
        }
        if (root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        int current_level = 1;
        int queue_size;
        while (current_level < d-1 & !q.empty()) {
            queue_size = q.size();
            while (queue_size > 0) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                queue_size--;
            }
            current_level++;
        }
        if (q.empty()) return root;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            auto child = node->left;
            node->left = new TreeNode(v);
            node->left->left = child;
            child = node->right;
            node->right = new TreeNode(v);
            node->right->right = child;
        }

        return root;

    }
};