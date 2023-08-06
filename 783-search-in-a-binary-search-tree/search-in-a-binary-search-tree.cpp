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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return root;
        }

        TreeNode *temp = root;
        while(temp != nullptr){
            int currVal = temp->val;
            if(currVal == val){
                break;
            }
            if(currVal > val){
                temp = temp->left;
            }

            if(currVal < val){
                temp = temp->right;
            }
        }

        return temp;
    }
};