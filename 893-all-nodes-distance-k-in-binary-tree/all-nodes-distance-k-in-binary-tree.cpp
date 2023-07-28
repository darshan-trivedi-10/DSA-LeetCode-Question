/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    unordered_map<int,vector<int>> mpp;
    vector<int> nodes;
    unordered_set<int> visited;

    void buildGraph(TreeNode *root, TreeNode *parent){
        if(root != nullptr && parent != nullptr){
            mpp[root->val].push_back(parent->val);
            mpp[parent->val].push_back(root->val);
        }
        if(root->left){
            buildGraph(root->left, root);
        }

        if(root->right){
            buildGraph(root->right, root);
        }
    }

    void dfs(int node, int k){
        if(k == 0){
            nodes.push_back(node);
            return;
        }

        for(int element : mpp[node]){
            if(visited.find(element) == visited.end()){
                visited.insert(element);
                dfs(element, k - 1);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, nullptr);
        visited.insert(target->val);
        dfs(target->val, k);
        return nodes;
    }
};