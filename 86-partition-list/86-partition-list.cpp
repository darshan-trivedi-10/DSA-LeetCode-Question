class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *second = new ListNode(-1);
        ListNode *first = new ListNode(-1);

        ListNode *rightPart = second;
        ListNode *leftPart = first;

        while (head != NULL)
        {
            if (head->val < x)
            {
                leftPart->next = head;
                leftPart = leftPart->next;
            }
            else
            {
                rightPart->next = head;
                rightPart = rightPart->next;
            }

            head = head->next;
        }

        leftPart->next = second->next;
        rightPart->next = NULL;

        return first->next;
    }
};