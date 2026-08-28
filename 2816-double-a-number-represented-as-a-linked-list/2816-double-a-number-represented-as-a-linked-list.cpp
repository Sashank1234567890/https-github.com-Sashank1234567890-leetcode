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
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL) {
            
            int newVal = curr->val * 2;
            
            if(newVal < 10) {
                curr->val = newVal;
            } else if(prev != NULL) {
                curr->val = newVal%10;
                
                prev->val += 1;
            } else {
                ListNode* newHead = new ListNode(1);
                newHead->next = curr;
                curr->val = newVal%10;
                head = newHead;
            }
            
            prev = curr;
            curr = curr->next;
            
        }
        
        
        return head;
    }
};