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
    int mx;
    ListNode* remove(ListNode* head){
         if(!head){
            return NULL;
         }
         if(head->next==NULL){
            mx=head->val;
            return head;
         }
         ListNode* next=remove(head->next);
         if(head->val<mx){
               return next; 
         }
         mx=head->val;
         head->next=next;
        return head;
         
    }
    ListNode* removeNodes(ListNode* head) {
        mx=INT_MIN;
        return remove(head);
    }
};