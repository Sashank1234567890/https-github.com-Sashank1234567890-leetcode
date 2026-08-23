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
    ListNode* temp;
    int cnt;

    Solution(ListNode* head) {
        temp = head;

        cnt = 0;

        ListNode* curr = head;

        while(curr) {
            cnt++;
            curr = curr->next;
        }
    }
    
    int getRandom() {

        int k = rand() % cnt;

        ListNode* curr = temp;

        while(k--) {
            curr = curr->next;
        }

        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */