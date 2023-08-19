class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> paths;
        if (root == nullptr) {
            return paths;
        }

        int val = root->val;
        auto left_paths = binaryTreePaths(root->left);
        auto right_paths = binaryTreePaths(root->right);

        for (const auto& path : left_paths) {
            paths.push_back(std::to_string(val) + "->" + path);
        }

        for (const auto& path : right_paths) {
            paths.push_back(std::to_string(val) + "->" + path);
        }

        if (paths.empty()) {
            paths.push_back(std::to_string(val));
        }

        return paths;
    }
};
