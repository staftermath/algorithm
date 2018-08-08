//
// Created by gwengww on 8/7/18.
// 4ms 100%
// time O(n);
// space O(1);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // if (head == nullptr) return head;
        ListNode* dummy_head = new ListNode(0);
        ListNode* new_head = dummy_head;
        ListNode* dummy_tail = new ListNode(0);
        ListNode* new_tail = dummy_tail;
        while (head != nullptr) {
            if (head->val < x) {
                new_head->next = head;
                new_head = new_head->next;
            } else {
                new_tail->next = head;
                new_tail = new_tail->next;
            }
            head = head->next;
        }
        new_head->next = dummy_tail->next;
        new_tail->next = nullptr;
        return dummy_head->next;
    }
};