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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minV = min(p->val, q->val);
        int maxV = max(p->val, q->val);

        while(root != nullptr){
            if(root->val > maxV){
                root = root->left;
            }else if(root->val < minV){
                root = root->right;
            }else{
                break;
            }
        }

        return root;
    }
};