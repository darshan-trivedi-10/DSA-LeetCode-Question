
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
        {
            return head;
        }

        int len = 1;
        ListNode *newH, *tail;
        newH = tail = head;

        while (tail->next != NULL)
        {
            tail = tail->next;
            len++;
        }

        tail->next = head;

        if (k % len)
        {
            k = k%len;
            for (int i = 0; i < len - k; i++)
            {
                tail = tail->next;
            }
        }

        newH = tail->next;
        tail->next = nullptr;
        return newH;
    }
};