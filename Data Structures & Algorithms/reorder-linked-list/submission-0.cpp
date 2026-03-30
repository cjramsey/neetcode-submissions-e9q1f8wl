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
    void reorderList(ListNode* head) {
        // at cur
        // save cur->next as old_next
        // set cur->next to cur->next->next
        // set old_next->next to prev
        // advance cur to cur->next
        // advance prev to old_next;
        if (head == nullptr) return;
        if (head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* next = slow->next;
        slow->next = nullptr;
        slow = next;
        while (slow != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* cur = head;
        while (cur != nullptr && prev != nullptr) {
            ListNode* prev_next = prev->next;
            prev->next = cur->next;
            cur->next = prev;
            cur = cur->next->next;
            prev = prev_next;
        }
    }
};
