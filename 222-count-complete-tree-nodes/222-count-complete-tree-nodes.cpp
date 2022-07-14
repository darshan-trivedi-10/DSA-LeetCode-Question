class Solution
{
public:
    int findleftHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            root = root->left;
            height++;
        }
        return height;
    }

    int findrightHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            root = root->right;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = findleftHeight(root);
        int rh = findrightHeight(root);
        if (lh == rh)
        {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};