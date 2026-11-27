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
        int n = lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];
        ListNode* dummy = new ListNode(-1);
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
        for(int i=0; i<n; i++) {
            ListNode* node = lists[i];
            if(node != nullptr) minHeap.push({node->val, node});
        }
        ListNode* temp = dummy;
        while(!minHeap.empty()) {
            ListNode* curr = minHeap.top().second;
            minHeap.pop();
            if(curr->next != nullptr) minHeap.push({curr->next->val, curr->next}); // inserting next ele in heap that was followed by the minimum element that we popped out
            temp->next = curr;
            temp = curr;
        }
        return dummy->next;
    }
};
