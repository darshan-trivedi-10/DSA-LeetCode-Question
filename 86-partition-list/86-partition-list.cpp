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
        
        ListNode *first,*second, *temp = head, *dummy = NULL;
        first = new ListNode(-1);
        second = new ListNode(-1);
        head = NULL;
        while(temp != NULL){
            if(temp->val<x){
                if(head==NULL){
                    head = temp;
                }
                first->next = temp;
                first = first->next;
            }else{
                if(dummy==NULL){
                    dummy = temp;
                }
                second->next = temp;
                second = second->next;
            }
            
            temp = temp->next;
        }
        if(head==NULL){
            head = dummy;
        }
        second->next = NULL;
        first->next = dummy;
        return head;      
    }
};