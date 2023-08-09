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

    vector<TreeNode*> Helper(int start, int end){
        vector<TreeNode*> trees;
        if(start > end || start <= 0){
            trees.push_back(nullptr);
            return trees;
        }

        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftSubtree = Helper(start, i - 1);
            vector<TreeNode*> rightSubtree = Helper(i + 1, end);

            for(auto left : leftSubtree){
                for(auto right : rightSubtree){
                    TreeNode *root = new TreeNode(i);
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
        if(n == 0){
            return vector<TreeNode*>();
        }

        return Helper(1, n);
    }
};