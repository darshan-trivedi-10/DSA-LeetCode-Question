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
    
    int countgoodNodes(TreeNode *root, int maxNode){
        if(root==NULL){
            return 0;
        }
        
        maxNode = max(maxNode, root->val);
        if(root->val>=maxNode){
            return 1 + countgoodNodes(root->left, maxNode) + countgoodNodes(root->right, maxNode);
        }
        
        return countgoodNodes(root->left, maxNode) + countgoodNodes(root->right, maxNode);
        
    }
    
    
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return countgoodNodes(root, root->val);
    }
};