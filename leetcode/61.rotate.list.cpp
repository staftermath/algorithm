//
// Created by gwengww on 4/27/18.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        // find size
        ListNode* temp = head;
        int size = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            size++;
        }
        ListNode* tail = temp; // need to assign next of tail to head;
        k %= size;
        if (k == 0) return head;
        temp = head;
        for (int i=0; i< size-k-1; i++) {
            temp = temp->next;
        }
        ListNode* result = temp->next;
        temp->next = NULL; // set tail to be NULL
        tail->next = head; // move to the end;
        return result;
    }
};