/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode *buildTree(vector<int> &nodes, int left, int right){
        if(left > right){
            return nullptr;
        }

        int mid = (left + right)/2;
        TreeNode *root = new TreeNode(nodes[mid]);
        root->left = buildTree(nodes, left, mid - 1);
        root->right = buildTree(nodes, mid + 1, right);

        return root;
    }


public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nodes;
        while(head != nullptr){
            nodes.push_back(head->val);
            head = head->next;
        }        

        return buildTree(nodes, 0, nodes.size() - 1);
    }
};