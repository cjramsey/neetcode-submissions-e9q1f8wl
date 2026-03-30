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
        if (head->next == nullptr) return {};

        int length = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            ++length;
        }
        
        ListNode dummy_node{0, head};
        ListNode* dummy{&dummy_node};
        cur = dummy;

        for (int i = 0; i < length - n; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;

        return dummy->next;
    }
};
