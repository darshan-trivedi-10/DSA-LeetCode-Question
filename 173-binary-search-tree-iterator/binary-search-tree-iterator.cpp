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
class BSTIterator {

    TreeNode *root;
    stack<TreeNode*> nodeStack;


public:
    BSTIterator(TreeNode* root) {
        this->root = root;
    }
    
    int next() {

        // going this the left node in tree/subtree
        while(root != nullptr){
            nodeStack.push(root);
            root = root->left;
        }

        TreeNode *node = nodeStack.top();
        nodeStack.pop();
        int val = node->val; 
        root = node->right; // now go to the right becuase left is nullptr
        return val;
    }
    
    bool hasNext() {
        return (!nodeStack.empty() || root != nullptr);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */