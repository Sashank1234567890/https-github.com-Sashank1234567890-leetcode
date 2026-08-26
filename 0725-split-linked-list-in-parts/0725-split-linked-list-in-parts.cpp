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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int L = 0;
        ListNode* curr = head;

        while(curr) {
            L++;
            curr = curr->next;
        }

        int nodes = L / k;
        int extra = L % k;

        vector<ListNode*> result(k, NULL);

        curr = head;

        for(int i = 0; i < k; i++) {

            if(!curr)
                break;

            result[i] = curr;

            int count = nodes;

            if(extra > 0) {
                count++;
                extra--;
            }

            ListNode* prev = NULL;

            for(int j = 0; j < count; j++) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
        }

        return result;
    }
};