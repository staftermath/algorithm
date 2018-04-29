//
// Created by gwengww on 4/29/18.
// beat 75.29%
// time complexity O(N)
// space coplexity O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n==0 || head == nullptr) return head;
        ListNode* tail = head;
        while (n-1 > 0) {
            if (tail->next == nullptr) return head;
            tail = tail->next;
            n--;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (tail->next != nullptr) {
            tail = tail->next;
            head = head->next;
        }
        head->next = head->next->next; // skip nth node from last
        return dummy->next;
    }
};