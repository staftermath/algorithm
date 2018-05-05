//
// Created by gwengww on 5/5/18.
// beat 81.78%
// time complexity O(N)
// space complexity O(1)

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* pNode = root;
        TreeNode* dummy = new TreeNode(0);
        dummy->right = root;
        TreeNode* upper = dummy;
        bool changeRight = true;
        while (pNode != nullptr) {
            if (pNode->val == key) break;
            else if (pNode->val > key) {
                upper = pNode;
                changeRight = false;
                pNode = pNode->left;

            }
            else {
                upper = pNode;
                changeRight = true;
                pNode = pNode->right;
            }
        }
        if (pNode == nullptr) return root; // didn't find key
        if (changeRight) {
            upper->right = deleteRoot(pNode);
        } else {
            upper->left = deleteRoot(pNode);
        }
        return dummy->right;
    }
private:
    TreeNode* deleteRoot(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return nullptr;
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        TreeNode* newRoot = root->right;
        TreeNode* lower;
        if (newRoot->left == nullptr) {
            newRoot->left = root->left;
            return newRoot;
        } else {
            lower = newRoot->left;
            while (lower->left != nullptr) {
                lower=lower->left;
            }
            lower->left = root->left;
            return newRoot;
        }

    }
};