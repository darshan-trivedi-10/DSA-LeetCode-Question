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
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        vector<int> level;
        queue<pair<TreeNode*, int>> nodeQueue;
        nodeQueue.push({root, 1});
        int currLevel = 1;
        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            for(int i = 0; i < size; i++){
                TreeNode *node = nodeQueue.front().first;
                int level = nodeQueue.front().second;
                nodeQueue.pop();
                if(currLevel != level){
                    return false;
                }
                currLevel++;
                if(node->left){
                    nodeQueue.push({node->left, 2 * level});
                }

                if(node->right){
                    nodeQueue.push({node->right, 2 * level + 1});
                }

            }
        }

        return true;
    }
};