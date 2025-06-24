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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next ==NULL){
            return head;
        }
        ListNode* tail = head;
        int n=1;
        while(tail->next != NULL){
            tail = tail->next;
            n++;
        }
        if(k%n == 0){  // if not done then in upcoming code pivot will point to tail so pivot->next will give error
            return head;  
        }
        ListNode* pivot = head;
        for(int i=0; i< (n- (k%n)-1 ); i++){
            pivot=pivot->next;
        }
        ListNode* newhead = pivot->next;
        pivot->next = NULL;
        tail->next = head ;

        return newhead;

    }
};
