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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result = {};
        if (root == NULL || root->left == NULL && root->right == NULL) return {};
        fillDepth(root->left);
        fillDepth(root->right);
        groupNode();
        for (auto aPair: groupedNodes) {
            vector<bool> picked(aPair.second.size(), false);
            for (int i=0; i<aPair.second.size()-1; i++) {
                if (!picked[i]) {
                    for (int j=i+1; j<aPair.second.size(); j++) {
                        if(compareTree(aPair.second[i], aPair.second[j])) {
                            if (!picked[i]) {
                                picked[i] = true;
                                result.push_back(aPair.second[i]);
                            }
                            picked[j] = true;
                        }
                    }
                }
            }
        }
        return result;
    }
    
private:
    unordered_map<TreeNode*, int> depth;
    unordered_map<int, vector<TreeNode*>> groupedNodes;
    
    void fillDepth(TreeNode* root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) depth[root] = 1;
        else if (root->left != NULL && root->right == NULL) {
            fillDepth(root->left);
            depth[root] = depth[root->left] + 1;
        } else if (root->left == NULL && root->right != NULL) {
            fillDepth(root->right);
            depth[root] = depth[root->right] + 1;
        } else {
            fillDepth(root->left);
            fillDepth(root->right);
            depth[root] = max(depth[root->left], depth[root->right]) + 1;
        }
    }
    
    void groupNode() {
        for (auto aPair: depth) {
            if (groupedNodes.find(aPair.second) != groupedNodes.end()) {
                groupedNodes[aPair.second].push_back(aPair.first);
            } else {
                groupedNodes[aPair.second] = {aPair.first};
            }
        }
    }
    
    bool compareTree(TreeNode* aTree, TreeNode* bTree) {
        if ((aTree == NULL) && (bTree == NULL)) return true;
        if ((aTree == NULL) != (bTree == NULL)) return false;
        if (aTree->val != bTree->val) return false;
        return compareTree(aTree->left, bTree->left) && compareTree(aTree->right, bTree->right);
    }
    
    
};
