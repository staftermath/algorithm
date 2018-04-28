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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* begin=dummy;
        ListNode* mid=NULL;
        ListNode* end=NULL;
        ListNode* temp=NULL;
        begin = dummy;
        while (begin != NULL) {
            mid = begin->next;
            if (mid == NULL) break;
            end = mid->next;
            if (end == NULL) break;
            swap(begin, mid, end); // mid and end have been swapped
            begin = mid;
        }
        return dummy->next;
    }
private:
    void swap(ListNode* begin, ListNode* mid, ListNode* end) {
        ListNode* temp = end->next;
        begin->next = end;
        end->next = mid;
        mid->next = temp;
    }
};