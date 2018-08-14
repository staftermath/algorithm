//
// Created by gwengww on 8/13/18.
// 28ms 97.22%
// time O(n)
// space O(n) <- can be optimized to be O(1) if reuse one of the ListNode

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        ListNode* head = new ListNode(0);
        auto result = head;
        int digit, v1, v2;
        auto head1 = l1;
        auto head2 = l2;
        while (head1 != nullptr || head2 != nullptr) {
            if (head1 == nullptr) {
                v1 = 0;
            } else {
                v1 = head1->val;
                head1 = head1->next;
            }
            if (head2 == nullptr) {
                v2 = 0;
            } else {
                v2 = head2->val;
                head2 = head2->next;
            }
            digit = v1+v2+add;
            add = digit/10;
            digit = digit%10;
            result->next = new ListNode(digit);
            result = result->next;
        }
        if (add != 0) result->next = new ListNode(add);
        return head->next;
    }
};