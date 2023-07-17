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

    void traversalHelper(TreeNode *root, vector<int> &nodes){
        if(root == NULL){
            return;
        }
        traversalHelper(root->left, nodes);
        nodes.push_back(root->val);
        traversalHelper(root->right, nodes);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        traversalHelper(root, nodes);
        return nodes;
    }
};