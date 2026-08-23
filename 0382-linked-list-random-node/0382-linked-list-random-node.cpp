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
    int cnt;
   vector<int>arr;
    Solution(ListNode* head) {
        cnt=0;
        arr.clear();
        ListNode* temp=head;
        while(temp){
            cnt++;
            arr.push_back(temp->val);
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int i=rand()%cnt;
        return arr[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */