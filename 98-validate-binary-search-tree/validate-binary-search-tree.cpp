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

private:
    bool verifyBST(TreeNode *root, long startR, long endR){
        if(root == nullptr){
            return true;
        }

        if(!(root->val > startR && root->val < endR)){
            return false;
        }

        return (verifyBST(root->left, startR, root->val) && verifyBST(root->right, root->val, endR));
    }



public:
    bool isValidBST(TreeNode* root) {
        return verifyBST(root, LONG_MIN, LONG_MAX);
    }
};