class Solution {
    private :

    TreeNode* rightMostElement(TreeNode *root){
        while(root->right != nullptr){
            root = root->right;
        }

        return root;
    }

    // this function help us to create bst after removing the node
    TreeNode* helper(TreeNode *root){
        if(root->left == nullptr){
            return root->right;
        }else if(root->right == nullptr){
            return root->left;
        }

        // right subtree of the node append at the right most element in the left subtree of the node
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = rightMostElement(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }

        if(root->val == key){
            return helper(root);
        }

        TreeNode *node = root;
        while(node != nullptr){
            if(node->val > key){
                if(node->left != nullptr && node->left->val == key){
                    node->left = helper(node->left);
                }else{
                    node = node->left;
                }
            }else{
                // go to right
                if(node->right != nullptr && node->right->val == key){
                    node->right = helper(node->right);
                }else{
                    node = node->right;
                }
            }
        }

        return root;
    }
};