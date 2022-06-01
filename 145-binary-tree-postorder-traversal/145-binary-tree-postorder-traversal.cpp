
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if(root==NULL){
            return {};
        }
        vector<int> postorder;
        stack<TreeNode *> s1;
        s1.push(root);

        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s1.pop();
            postorder.push_back(temp->val);

            if (temp->left)
            {
                s1.push(temp->left);
            }

            if (temp->right)
            {
                s1.push(temp->right);
            }
        }
        
        reverse(postorder.begin(), postorder.end());
        
        return postorder;
    }
};