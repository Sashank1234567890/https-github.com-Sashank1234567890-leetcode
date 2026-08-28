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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(begin(nums),end(nums));
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        ListNode* curr=head;
        tail->next=head;
        while(curr){
             if(st.contains(curr->val)){
                tail->next=curr->next;
             }
             else{
             tail=tail->next;
             }
             curr=curr->next;
        }
        return dummy->next;
    }
};