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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=nullptr) {
            temp = temp->next;
            cnt++;
        }
        int k = cnt-n;
        if(k==0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp = head;
        cnt = 0;
        while(cnt<k-1) {
            temp = temp->next;
            cnt++;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
};
