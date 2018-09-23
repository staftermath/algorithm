//
// Created by gwengww on 9/23/18.
// 56ms 30.17%
// time O(n)
// space O(1)

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
    void reorderList(ListNode* head) {
        // get part that needs to be reversed
        ListNode* slow = head;
        if (head == nullptr || head->next == nullptr) return;
        ListNode* fast = head->next;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;

        // reverse the second part
        ListNode* reversed = nullptr;
        ListNode* tmp = nullptr;
        fast = slow->next;
        while (fast != nullptr) {
            tmp = fast->next;
            fast->next = reversed;
            reversed = fast;
            fast = tmp;
        }
        // reconnect two parts
        ListNode* ptr = head;
        ListNode* tmp_reversed = nullptr;
        while (reversed != nullptr) {
            tmp = ptr->next;
            tmp_reversed = reversed->next;
            ptr->next = reversed;
            reversed->next = tmp;
            ptr = tmp;
            reversed = tmp_reversed;
        }
        // close the end
        slow->next = nullptr;
        return;
    }
};