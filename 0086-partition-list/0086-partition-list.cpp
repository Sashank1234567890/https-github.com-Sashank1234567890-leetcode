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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr=head;
        if(!head||!head->next)
        return head;
        ListNode* d1=new ListNode() ;
        ListNode* d2=new ListNode ();
         ListNode* l1=d1;
         ListNode* l2=d2;
      
        while(curr){
            int val =curr->val;
            if(val<x){
            l1->next=new ListNode(val);
            l1=l1->next;
            }else{
            l2->next=new ListNode(val);
            l2=l2->next;
            }
            curr=curr->next;
        }
        l1->next=d2->next;
        return d1->next;
    }
};