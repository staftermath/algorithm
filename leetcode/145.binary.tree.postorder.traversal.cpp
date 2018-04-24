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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> pStack;
        TreeNode* previous = root;
        if (root == NULL) {
            return {};
        }
        
        pStack.push(root);
        while(!pStack.empty()) {
            auto node = pStack.top();
            
            if (node->left == previous || node->right == previous || (node->right == NULL && node->left == NULL)) {
                pStack.pop();
                result.push_back(node->val);
                previous = node;
                continue;
            }
            
            if (node->right != NULL) {
                pStack.push(node->right);
            }
            
            if (node->left != NULL) {
                pStack.push(node->left);
            }
            
        }
        return result;
    }
};
