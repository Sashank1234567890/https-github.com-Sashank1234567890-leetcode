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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
        return head;
        ListNode* temp=head;
        ListNode* temp2=head->next;
        ListNode*temp3=head->next;
        ListNode*prev=NULL;
        while(temp&&temp2){
            temp->next=temp2->next;
            temp2->next=temp;
              if(prev!=NULL)
              prev->next=temp2;
              prev=temp;
            temp=temp->next;
           
          
            if(temp)
            temp2=temp->next;
        }
        return temp3;
    }
};