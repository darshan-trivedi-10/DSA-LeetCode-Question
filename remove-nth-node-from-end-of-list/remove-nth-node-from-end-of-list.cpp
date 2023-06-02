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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // n-1 th node i need to found 
        // size - n 
        // prev ->next = prev->next->next; --> node is removed
        // what is prev is not exit ?
        // 1 2 , n = 1 , 1 - 1 = 0,
        // curr = curr->next; --> return curr;

        // Find the nth or n-1 th node in the linked list
        /*
        // Approche 1 : 
            Find the size of Linkedlist 
            and travel the LinkedList and find node and do this 
            O(N) -> Finding the size of the Linked List
            O(N) -> travel to the element which we want tot remove

            O(2 * N) = O(N)
        */

        ListNode *start = new ListNode(-1);
        start->next = head;
        ListNode *slow = start, *fast = start;

        for(int i = 1; i <= n; i++){
            fast = fast->next;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return start->next;

    }
};