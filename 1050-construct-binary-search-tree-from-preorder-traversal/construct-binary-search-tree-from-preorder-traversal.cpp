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

private :
    TreeNode *build(vector<int> &arr, int &i, int bound){
        if(i == arr.size() || arr[i] > bound){
            return nullptr;
        }

        TreeNode *root = new TreeNode(arr[i++]);
        root->left = build(arr, i, root->val);
        root->right = build(arr, i, bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& arr) {
        int i = 0;
        return build(arr, i, INT_MAX);
    }
};