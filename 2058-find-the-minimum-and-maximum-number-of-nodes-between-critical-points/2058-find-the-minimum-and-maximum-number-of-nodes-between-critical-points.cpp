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
        vector<int> nodesBetweenCriticalPoints(ListNode *head)
        {
            int first = -1;
            int next = -1;
            ListNode *temp = head->next;
            int mn = INT_MAX;
            int mx = INT_MIN;
            int prev = head->val;
            int cnt = 0;
            while (temp && temp->next)
            {
                int nxt = temp->next->val;
                int cur = temp->val;
                if ((cur > nxt && cur > prev) || (cur < nxt && cur < prev))
                {
                    if (first == -1)
                    {
                        first = cnt;
                        
                    }
                    else
                    {
                        mn = min(mn, cnt - next );
                        mx = cnt - first ;
                    }
                    next = cnt;
                }
                cnt++;
                temp = temp->next;
                prev=cur;
            }

            if (mn == INT_MAX)
            {
                return { -1, -1 };
            }
            return {mn,mx};
        }
};