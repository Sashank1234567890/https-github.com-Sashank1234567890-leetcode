/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* oddEvenList(ListNode *head)
        {
            if (!head || !head->next)
                return head;
            ListNode*head2 = head->next;
            ListNode*tail1 = head;
            ListNode* tail2 = head2;

            while (tail1 && tail2 && tail1->next&&tail1->next->next)
            {
                tail1->next = tail1->next->next;
                if(tail1->next)
                tail2->next = tail1->next->next;
                // if(tail1->next){
                //     break;
                // }
                    tail1=tail1->next;
                    tail2=tail2->next;
            }
            tail1->next = head2;
            return head;
        }
};