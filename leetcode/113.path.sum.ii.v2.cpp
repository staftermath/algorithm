//
// Created by gwengww on 6/10/18.
// 12 ms 84.41%

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
        vector<vector<int>> paths;
        vector<int> path;
        pathSum(root, path, sum, paths);
        return paths;
    }
private:
    void pathSum(TreeNode* root, vector<int>& path, int sum, vector<vector<int>>& paths) {
        if (root == nullptr) return;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum) {
                paths.push_back(path);
            }
            path.pop_back();
            return;
        }

        pathSum(root->left, path, sum-root->val, paths);
        pathSum(root->right, path, sum-root->val, paths);
        path.pop_back();
        return;
    }
};