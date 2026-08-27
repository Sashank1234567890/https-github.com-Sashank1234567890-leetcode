class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* p1 = head;
        ListNode* p2 = head;

        int count = 0;

        while(p1)
        {
            p1 = p1->next;
            count++;

            if(count > n+1)
                p2 = p2->next;
        }

        if(count == n)
            return head->next;

        p2->next = p2->next->next;

        return head;
    }
};