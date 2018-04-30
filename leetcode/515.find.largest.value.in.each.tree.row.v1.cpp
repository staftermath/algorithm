//
// Created by gwengww on 4/30/18.
// beat 8.21%.
// beat 95.90% if use INT_MIN instead of  pQueue.front()->val.
// time: O(N)
// space: O(2*B)

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result = {};
        queue<TreeNode*> pQueue = {};
        if (root == nullptr) return result;
        pQueue.push(root);
        while (!pQueue.empty()) {
            int size = pQueue.size(); // keep a copy of current queue size
            int maximum = pQueue.front()->val; // avoid using INT_MIN; use INT_MIN will be a lot faster.
            for (int i=0; i<size; i++) {
                TreeNode* node = pQueue.front();
                pQueue.pop();
                maximum = max(maximum, node->val);
                if (node->left != nullptr) pQueue.push(node->left);
                if (node->right != nullptr) pQueue.push(node->right);
            }
            result.push_back(maximum);
        }
        return result;
    }
};