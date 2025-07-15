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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > >minHeap;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                minHeap.push({lists[i] -> val, lists[i]});
            }
        } 
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!minHeap.empty()){
            auto top = minHeap.top();
            ListNode* node = top.second;
            minHeap.pop();

            temp->next = node;
            temp = node;
            if(node->next != NULL){
                minHeap.push({node->next->val, node->next});
            }
        }
        return dummy->next;
    }
};
