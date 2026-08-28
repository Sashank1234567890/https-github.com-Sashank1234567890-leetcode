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
    int carry;
    void doubleval(ListNode* head){
        if(!head){
            return ;
        }
        if(head->next==NULL){
            int value=head->val*2;
            head->val=value%10;
            carry=value/10;
            return;
        }
        doubleval(head->next);
        int value=head->val*2+carry;
            head->val=value%10;
            carry=value/10;
        
    return ;
    }
    ListNode* doubleIt(ListNode* head) {
        carry=0;
        doubleval(head);
        if(carry){
          ListNode* newnode= new ListNode(carry);
          newnode->next=head;
          head=newnode;  
        }
        return head;
    }
};