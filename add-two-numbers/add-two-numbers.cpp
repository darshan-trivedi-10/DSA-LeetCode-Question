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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;

        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l1 = l1->next, l2 = l2->next;
            carry = sum/10;
        }

        while(l1 != NULL){
            int sum = l1->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l1 = l1->next;
            carry = sum/10;
        }

        while(l2 != NULL){
            int sum = l2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l2 = l2->next;
            carry = sum/10;
        }

        while(carry > 0){
            tail->next = new ListNode(carry%10);
            tail = tail->next;
            carry = carry/10;
        }

        return head->next;
    }
};