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
    
    bool Helper(TreeNode* left, TreeNode* right){
        if(left==NULL || right==NULL){
            return left==right;
        }
        
        if(left->val != right->val){
            return false;
        }
        
        bool l = Helper(left->left, right->right);
        bool r = Helper(left->right, right->left);
        
        return (l&r);
    }
    
    
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        return Helper(root->left, root->right);
    }
};