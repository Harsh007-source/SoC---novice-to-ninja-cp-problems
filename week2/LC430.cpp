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
    Node* flatten(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){  // found a valid child
                Node* next = curr->next;  // store curr->next
                curr->next = flatten(curr->child);  // flatten return the head of linear LL 
                curr->next->prev = curr;
                curr->child = NULL;

                while(curr->next != NULL){  // to get tail of flatten LL
                    curr = curr->next;
                }
                if(next != NULL){   // attach tail with next
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;  // when child is null
        }
        return head;
    }
};
