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
    int findAns(TreeNode* root, int &ans){
        if(root==NULL){
            return 0;
        }
        
        int h1 = findAns(root->left, ans);
        int h2 = findAns(root->right, ans);
        ans = max(ans, abs(h1-h2));
        
        return 1 + max(h1,h2);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        int ans = 0;
        findAns(root, ans);
        return ans<=1;
    }
};