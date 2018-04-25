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
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maximum;
    }
private:
    int maximum = INT_MIN;
    int helper(TreeNode* root) {
        int left, right, result;
        if (root == NULL) return 0;
        maximum = max(maximum, root->val);
        left = helper(root->left);
        right = helper(root->right);
        if (root->left != NULL) { 
           maximum = max(maximum, left+root->val);
        }
        if (root->right != NULL) {
            maximum = max(maximum, right+root->val);
        }
        if (root->left != NULL && root->right != NULL) {
            maximum = max(maximum, left + right + root->val);
        }
        result = max(left, right) + root->val;
        return max(root->val, result);
    }
};
