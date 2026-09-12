/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node*tail;
    Node* flatten(Node* head) {
        if(!head)
        return head;
        tail=head;
        if(head->child){
            Node*next=head->next;
            head->next=flatten(head->child);
            head->child=NULL;
            head->next->prev=head;
            tail->next=next;
            if(next)
            next->prev=tail;
        }
        head->next=flatten(head->next);
    return head;
    }
};