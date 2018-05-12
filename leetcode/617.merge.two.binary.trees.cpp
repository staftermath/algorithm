//
// Created by gwengww on 5/8/18.
// beat 94.18%
// time complex O(N)
// space O(2*W)

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        queue<TreeNode*> toQueue, fromQueue;
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        toQueue.push(t1);
        fromQueue.push(t2);
        while (!toQueue.empty()) {
            auto to = toQueue.front();
            toQueue.pop();
            auto from = fromQueue.front();
            fromQueue.pop();
            to->val += from->val;

            // merge left
            if (to->left != nullptr && from->left != nullptr) {
                toQueue.push(to->left);
                fromQueue.push(from->left);
            } else if (to->left == nullptr && from->left != nullptr) {
                to->left = from->left;
            }
            // merge right
            if (to->right != nullptr && from->right != nullptr) {
                toQueue.push(to->right);
                fromQueue.push(from->right);
            } else if (to->right == nullptr && from->right != nullptr) {
                to->right = from->right;
            }
        }
        return t1;
    }
};