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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr){
            return ans;
        }

        int val = root->val;
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);

        for(auto str : left){
            string path = to_string(val) + "->" + str;
            ans.push_back(path);
        }

        for(auto str : right){
            string path = to_string(val) + "->" + str;
            ans.push_back(path);
        }

        if(ans.size() == 0){
            string path = to_string(root->val);
            ans.push_back(path);
        }

        return ans;
    }
};