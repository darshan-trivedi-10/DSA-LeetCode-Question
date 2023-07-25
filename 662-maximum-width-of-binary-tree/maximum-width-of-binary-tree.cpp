/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    int maxWidth = 0;
    if (root == nullptr) {
      return maxWidth;
    }

    queue<pair<TreeNode *, int>> nodeQueue; // node, level
    nodeQueue.push({root, 0});

    while (!nodeQueue.empty()) {
      int size = nodeQueue.size();
      int firstIdx = INT_MAX, lastIdx = INT_MIN;
      for (int i = 0; i < size; i++) {
        TreeNode *node = nodeQueue.front().first;
        int index = nodeQueue.front().second;
        nodeQueue.pop();

        firstIdx = min(firstIdx, index);
        lastIdx = max(lastIdx, index);

        if (node->left != nullptr) {
          nodeQueue.push({node->left, ((2LL * index) + 1)});
        }

        if (node->right != nullptr) {
          nodeQueue.push({node->right, ((2LL * index) + 2)});
        }
      }
      maxWidth = max(maxWidth, lastIdx - firstIdx + 1);
    }

    return maxWidth;
  }
};