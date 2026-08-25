class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mp;

        int sum = 0;
        ListNode* curr = dummy;

        // First pass: store the last node for each prefix sum
        while (curr) {
            sum += curr->val;
            mp[sum] = curr;
            curr = curr->next;
        }

        // Second pass: skip zero-sum sequences
        sum = 0;
        curr = dummy;

        while (curr) {
            sum += curr->val;
            curr->next = mp[sum]->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};