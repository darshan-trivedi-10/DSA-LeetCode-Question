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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;

        stack<TreeNode*> st;
        while(true){
            // cout<<st.size()<<" ";
            if(root != nullptr){
                st.push(root);
                root = root->left;
            }else{
                if(st.empty()){
                    break;
                }
                root = st.top();
                nodes.push_back(root->val);
                st.pop();
                root = root->right;
            }
        }

        return nodes;
    }

    int idx = 0;
    vector<int> inorder;


public:
    BSTIterator(TreeNode* root) {
        idx = -1;
        inorder = inorderTraversal(root);
    }
    
    int next() {
        idx++;
        return inorder[idx];
    }
    
    bool hasNext() {
        return ((idx + 1) != inorder.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */