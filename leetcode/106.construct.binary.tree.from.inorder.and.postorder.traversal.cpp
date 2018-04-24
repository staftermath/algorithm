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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0; i<inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size()-1,
                      postorder, 0, postorder.size()-1);
    }
    
private:
    unordered_map<int, int> hash;
    TreeNode* helper(vector<int>& inorder, int inorder_start, int inorder_end, 
                     vector<int>& postorder, int postorder_start, int postorder_end) {
        if (inorder_start > inorder_end) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postorder_end]);
        
        int left_inorder_start = inorder_start;
        int left_inorder_end = hash[root->val] - 1;
        int left_postorder_start = postorder_start;
        int left_postorder_end = left_inorder_end - left_inorder_start + left_postorder_start;
        int right_inorder_start = left_inorder_end + 2;
        int right_inorder_end = inorder_end;
        int right_postorder_start = left_postorder_end + 1;
        int right_postorder_end = postorder_end - 1;
        
        root->left = helper(inorder, left_inorder_start, left_inorder_end,
                            postorder, left_postorder_start, left_postorder_end);
        root->right = helper(inorder, right_inorder_start, right_inorder_end,
                            postorder, right_postorder_start, right_postorder_end);
        
        
        return root;
        
    }
};
