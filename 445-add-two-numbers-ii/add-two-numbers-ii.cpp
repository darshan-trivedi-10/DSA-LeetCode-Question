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

    ListNode* reverseLL(ListNode *head){
        ListNode *prev = NULL, *curr = head;
        while(curr != NULL){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }


public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        ListNode *head = new ListNode(-1);
        ListNode *temp = head;

        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            int sum = l1->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
            l1 = l1->next;
        }

        while(l2 != NULL){
            int sum = l2->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
            l2 = l2->next;
        }

        while(carry > 0){
            temp->next = new ListNode(carry%10);
            temp = temp->next;
            carry = carry/10;
        }

        return reverseLL(head->next);

    }
};