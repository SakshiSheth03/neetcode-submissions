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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d1 = l1;
        ListNode* d2 = l2;
        int carry = 0;
        ListNode* res = new ListNode(-1);
        ListNode* curr = res;
        while(d1!=nullptr && d2!= nullptr) {
            int d = (d1->val + d2->val + carry) % 10;
            ListNode* node = new ListNode(d);
            carry = (d1->val +d2->val) / 10;
            curr->next = node;
            d1 = d1->next;
            d2 = d2->next;
            curr = curr->next;
        }
        while(d1!=nullptr) {
            int d = (d1->val + carry) % 10;
            carry = (d1->val + carry) / 10;
            ListNode* node = new ListNode(d);
            curr->next = node;
            d1 = d1->next;
            curr = curr->next;
        }
        while(d2!=nullptr) {
            int d = (d2->val + carry) % 10;
            carry = (d2->val + carry) / 10;
            ListNode* node = new ListNode(d);
            curr->next = node;
            d2 = d2->next;
            curr = curr->next;
        }
        if(carry) {
            ListNode* node = new ListNode(carry);
            curr->next = node;
        }
        return res->next;
    }
};
