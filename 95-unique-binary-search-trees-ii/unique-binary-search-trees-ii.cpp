class Solution {
    vector<TreeNode*> Helper(int start, int end) {
        vector<TreeNode*> trees;

        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = Helper(start, i - 1);
            vector<TreeNode*> rightSubtrees = Helper(i + 1, end);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return Helper(1, n);
    }
};