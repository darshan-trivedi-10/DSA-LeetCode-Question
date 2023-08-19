class Solution {
public:
    int lengthOfLinkedList(ListNode* head){
        ListNode* temp = head;
        int length = 0;
        while(temp!=NULL){
            temp = temp->next;
            length++;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* prev = dummyHead;
        ListNode* cur = head;
        ListNode* next = NULL;
        int length=lengthOfLinkedList(head);
        while(length>=k){
            cur = prev->next;
            next = cur->next; 
            for(int i=1;i<k;i++){
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = cur->next;
            }
            prev = cur;
            length-=k;
        }

        return dummyHead->next;
    }
};