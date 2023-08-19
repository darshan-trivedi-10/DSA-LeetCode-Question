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
    int lengthOfLL(ListNode *head){
        ListNode *temp = head;
        int length = 0;

        while(temp != nullptr){
            temp = temp->next;
            length++;
        }

        return length;
    }

    ListNode *reverseKGroup(ListNode *head, int k , int length){
        if(length < k){
            return head;
        }

        int count = 0;
        ListNode *prev = nullptr, *next = nullptr, *curr = head;
        while(count < k && curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != nullptr){
            head->next = reverseKGroup(next, k, length - k);
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = lengthOfLL(head);
        return reverseKGroup(head, k, length);
    }
};