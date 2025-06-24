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

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* Next = head->next;
        while(Next != NULL){
            head->next = prev;
            prev = head;
            head = Next;
            Next = head->next;
        }
        head->next = prev;
        return head;
    }
    void reorderList(ListNode* head) {
        //find the middle
        // reverse the 2nd half
        // use two pointer to merge alternatively
        if(head == NULL || head->next == NULL){
            return;
        }
        ListNode* slow= head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revhead = reverse(slow->next);
        slow->next = NULL;
        ListNode* c1 = head;
        ListNode* c2 = revhead;
        ListNode* n1 = head->next;
        ListNode* n2 = revhead->next;
        while(n1 !=NULL && n2!= NULL){
            c1->next = c2; c2->next = n1;
            c1=n1; c2=n2;
            n1 = n1->next;
            n2 = n2->next;
        }
        if(n1 != NULL && n2 == NULL){
            c1->next = c2;
            c2->next = n1;
        }else{  // n1 = n2 = NULL
            c1->next = c2;
        }
    }
};
