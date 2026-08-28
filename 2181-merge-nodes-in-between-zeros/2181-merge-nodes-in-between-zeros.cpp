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
    ListNode* mergeNodes(ListNode* head) {
    int sum=0;
    ListNode* curr=head;
    ListNode* ans=new ListNode(-1);
    ListNode* tail=ans;
    while(curr){
        if(curr->val==0){
            if(sum>0){
                tail->next=new ListNode(sum);
                tail=tail->next;
                sum=0;   
            }
            }
            sum+=curr->val;
            curr=curr->next;
        
    }

    return ans->next;}
};