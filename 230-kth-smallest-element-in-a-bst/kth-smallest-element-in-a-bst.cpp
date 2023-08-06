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
    vector<int> res;
    void build(TreeNode *root, int k){
        if(root == nullptr){
            return;
        }

        build(root->left, k);
        res.push_back(root->val);
        build(root->right, k);
    }


public:
    int kthSmallest(TreeNode* root, int k) {
        build(root, k);
        sort(res.begin(), res.end());
        return res[k-1];
    }
};