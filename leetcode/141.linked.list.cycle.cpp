//
// Created by gwengww on 4/29/18.
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
    bool hasCycle(ListNode *head) {
        ListNode* tail = head;
        if (head == nullptr) return false;
        while (tail->next != nullptr && tail->next->next != nullptr) {
            tail = tail->next->next;
            head = head->next;
            if (head == tail) return true;
        }
        return false;
    }
};