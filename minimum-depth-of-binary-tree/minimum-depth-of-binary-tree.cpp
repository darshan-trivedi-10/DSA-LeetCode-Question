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

//     2
//    /\
//     3
//     /

public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int left = INT_MAX, right = INT_MAX;

        if(root->left == NULL && root->right == NULL){
            return 1;
        }

        if(root->left){
            left = min(left, minDepth(root->left));
        }

        if(root->right){
            right = min(right, minDepth(root->right));
        }

        return 1 + min(left, right);
    }
};