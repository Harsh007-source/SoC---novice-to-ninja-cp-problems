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
    ListNode* mergeTwo(ListNode* head1, ListNode* head2){  // leetcode 21
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL? head2 : head1;
        }
        if(head1->val < head2->val){
            head1->next = mergeTwo(head1->next, head2);
            return head1;
        }else{
            head2->next = mergeTwo(head1, head2->next);
            return head2;
        }
    }
    ListNode* findMiddle(ListNode* head){  // slow-fast method
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head; 
        ListNode* rightHead = middle->next;
        middle->next = NULL;
        leftHead = sortList(leftHead); // right
        rightHead = sortList(rightHead);  // left
        return mergeTwo(leftHead, rightHead);
    }
};
