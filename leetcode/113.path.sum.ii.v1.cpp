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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        auto result = helper(root, sum);
        for (int i=0; i<result.size(); i++) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
private:
    vector<vector<int>> helper(TreeNode* root, int sum) {
        if (root == NULL) {
            return {};
        } else if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) return {{root->val}};
            else return {};
        }
        
        auto left = helper(root->left, sum - root->val);
        auto right = helper(root->right, sum - root->val);
        
        if (left.size() == 0 && right.size() == 0) return {};
        
        vector<vector<int>> result(left.size() + right.size());
        
        for (int i=0; i < left.size(); i++) {
            left[i].push_back(root->val);
            result[i] = left[i];
        }
        
        for (int j=0; j < right.size(); j++) {
            right[j].push_back(root->val);
            result[left.size() + j] = right[j];
        }
        
        return result;
    }
};
