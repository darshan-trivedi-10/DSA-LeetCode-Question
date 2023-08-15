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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* temp1 = new ListNode(-1);
        ListNode* temp2 = new ListNode(-1);

        ListNode* left = temp1;
        ListNode* right = temp2;

        while(head != nullptr){
            if(head->val < x){
                left->next = new ListNode(head->val);
                left = left->next;
            }else{
                right->next = new ListNode(head->val);
                right = right->next;
            }
            head = head->next;
        }

        left->next = temp2->next;

        return temp1->next;   
    }
};