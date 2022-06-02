class Solution
{
    int Helper(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        int s1 = max(0, Helper(root->left, ans));
        int s2 = max(0, Helper(root->right, ans));

        ans = max(ans, s1 + s2 + root->val);

        return max(s1, s2) + root->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        int S = Helper(root, ans);
        return ans;
    }
};