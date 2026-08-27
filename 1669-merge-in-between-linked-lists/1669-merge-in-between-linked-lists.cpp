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
        ListNode* mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
        {
            ListNode *ptr1 = list1;
            ListNode *ptr2 = list2;
            int x = a - 1;
            while (x--)
            {
                ptr1 = ptr1->next;
            }
            ListNode *temp = ptr1->next;
            ptr1->next = ptr2;
            int y = b - a;

            while (y--)
            {
                temp = temp->next;
            }
            while (ptr2 && ptr2->next)
            {
                ptr2 = ptr2->next;
            }
            ptr2->next = temp->next;
            temp->next = NULL;

                return list1;
        }
};