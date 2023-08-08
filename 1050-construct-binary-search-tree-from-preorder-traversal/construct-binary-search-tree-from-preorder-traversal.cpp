class Solution {
private:
    int findNextGreaterIndex(const vector<int> &preorder, int currentIndex) {
        int size = preorder.size();
        int i = currentIndex + 1;
        while (i < size) {
            if (preorder[currentIndex] < preorder[i]) {
                break;
            }
            i++;
        }
        return i;
    }

    TreeNode* buildBSTFromPreorder(const vector<int> &preorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[start]);
        int nextGreaterIndex = findNextGreaterIndex(preorder, start);

        root->left = buildBSTFromPreorder(preorder, start + 1, nextGreaterIndex - 1);
        root->right = buildBSTFromPreorder(preorder, nextGreaterIndex, end);

        return root;
    }

public:
    TreeNode* bstFromPreorder(const vector<int> &preorder) {
        return buildBSTFromPreorder(preorder, 0, preorder.size() - 1);
    }
};
