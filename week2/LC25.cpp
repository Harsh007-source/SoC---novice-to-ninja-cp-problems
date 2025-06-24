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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        // check if k nodes exists
        while(count < k){
            if(temp == NULL){
                return head;  // no change
            }
            temp = temp->next;
            count++;
        }
        // recursively call for rest of LL
        ListNode* prevNode = reverseKGroup( temp, k);

        // reverse current group
        temp = head;
        count = 0;
        while(count < k){
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }

        return prevNode;

    }
};
