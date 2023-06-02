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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail = NULL;

        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                if(head == NULL){
                    head = tail = l1;
                }else{
                    tail->next = l1;
                    tail = tail->next;
                }
                l1 = l1->next;
            }else{
                if(head == NULL){
                    head = tail = l2;
                }else{
                    tail->next = l2;
                    tail = tail->next;
                }
                l2 = l2->next;
            }
        }

        while(l1 != NULL){
            if(head == NULL){
                head = tail = l1;
            }else{
                tail->next = l1;
                tail = tail->next;
            }
            l1 = l1->next;
        }

        while(l2 != NULL){
            if(head == NULL){
                head = tail = l2;
            }else{
                tail->next = l2;
                tail = tail->next;
            }
            l2 = l2->next;
        }

        return head;
    }
};