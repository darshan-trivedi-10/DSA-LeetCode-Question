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

    int leftHeight(TreeNode* root){
        int height = 0;
        while(root){
            root = root->left;
            height++;
        }
        return height;
    }

    int rightHeight(TreeNode* root){
        int height = 0;
        while(root){
            root = root->right;
            height++;
        }
        return height;
    }


public:
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh){
            return (1 << rh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};