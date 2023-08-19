/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void Helper(TreeNode *root, vector<vector<int>> &ans, vector<int> &path, int targetSum){
        if(root == nullptr){
            return;
        }

        if(targetSum == root->val){
            if(root->left == nullptr && root->right == nullptr){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
                return;
            }
        }
        
        path.push_back(root->val);
        Helper(root->left, ans, path, targetSum - root->val);
        Helper(root->right, ans, path, targetSum - root->val);
        path.pop_back();
    }



public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        Helper(root, ans, path, targetSum);
        return ans;
    }
};