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
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* counter = head;
        ListNode* group_right;
        ListNode* prev_group_right = dummy;
        while (cur) {
            for (int i = 0; i < k; ++i) {
                if (counter) {
                    counter = counter->next;
                }
                else {
                    prev_group_right->next = cur;
                    return dummy->next;
                }
            }
            prev = nullptr;
            group_right = cur;
            for (int i = 0; i < k; ++i) {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            prev_group_right->next = prev;
            prev_group_right = group_right;
        }
        return dummy->next;
    }
};
