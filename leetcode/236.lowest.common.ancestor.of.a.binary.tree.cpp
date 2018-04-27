//
// Created by gwengww on 4/27/18.
//
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result  r= helper(root, p, q);
        return r.node;
    }
private:
    struct result {
        int count = 0;
        TreeNode* node;
    };
    result helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return result{0, NULL};
        result left = helper(root->left, p, q);
        result right = helper(root->right, p, q);
        if (left.count == 2) return left;
        if (right.count == 2) return right;
        if (left.count == 1 && right.count == 1) {
            return result{2, root};
        } else if (left.count == 1 || right.count == 1) {
            if (root == p || root == q) {
                return result{2, root};
            } else {
                return result{1, root};
            }
        } else {
            if (root == p || root == q) {return result{1, root};}
            return result{0, NULL};
        }
    }
};
