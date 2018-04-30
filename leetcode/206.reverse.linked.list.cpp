//
// Created by gwengww on 4/30/18.
//

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
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = nullptr;
        if (head == nullptr) return head;
        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = newhead;
            newhead = head;
            head = temp;
        }
        return newhead;
    }
};