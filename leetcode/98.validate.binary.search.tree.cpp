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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> pStack;
        int last;
        bool poped = false;
        if (root == NULL) return true;
        while(!pStack.empty() || root != NULL) {
            if (root != NULL) {
                pStack.push(root);
                root = root->left;
            } else {
                root = pStack.top();
                // cout << "root vale is " << root->val << endl;
                pStack.pop();
                if (!poped) {
                    // cout << "initialization last" << endl;
                    poped = true;
                    last = root->val; // initialized value of last
                } else if (root->val <= last) {
                    return false;
                }
                
                last = root->val;
                // cout << "last is " << last << endl;
                root = root->right;                
            }
            
        }
        return true;
    }

};
