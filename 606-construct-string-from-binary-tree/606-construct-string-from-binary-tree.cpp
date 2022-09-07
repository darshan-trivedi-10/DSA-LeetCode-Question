class Solution {
public:
    
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string s = to_string(root->val);
        if (!root->left && !root->right) s += "";  
        if (root->left) s += "(" + tree2str(root->left) + ")";
        if (!root->left && root->right) s += "()";
        if (root->right) s += "(" + tree2str(root->right) + ")";
        return s;
    }
};