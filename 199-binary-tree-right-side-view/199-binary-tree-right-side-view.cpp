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
    void Helper(TreeNode* root, vector<int> &ans, int level){
        if(root==NULL){
            return;
        }
        
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        
        Helper(root->right, ans, level+1);
        Helper(root->left, ans, level+1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        // Main Idea is to take first element in level when we move from right to left in level.
        // We can do this using recursion (Root, right, left)
        
        vector<int> ans;
        Helper(root, ans, 0);
        return ans;
    }
};