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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto lambda = [](ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)> pq; 

        for(ListNode* node : lists) {
            if(node != NULL) {
                pq.push(node);
            }
        }

        if(pq.empty()) {
            return NULL;
        }

        ListNode* head = pq.top();
        pq.pop();

        if(head->next != NULL) {
            pq.push(head->next);
        }

        ListNode* tail = head;

        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if(curr->next != NULL)
                pq.push(curr->next);
        }

        return head;

    }
};