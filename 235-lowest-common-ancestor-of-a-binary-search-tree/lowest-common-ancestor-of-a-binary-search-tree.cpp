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
        if(p == root || q == root || root == nullptr){
            return root;
        }

        int minV = min(p->val, q->val);
        int maxV = max(p->val, q->val);

        if(root->val > minV && root->val < maxV){
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr){
            return right;
        }
        if(right == nullptr){
            return left;
        }
        return root;
    }
};