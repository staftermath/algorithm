//
// Created by gwengww on 9/23/18.
// 36ms 63.65%
// time O(N)
// space O(N/2)

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
        int second_cnt = 1;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            second_cnt++;
        }
        if (fast->next != nullptr) slow = slow->next;
        vector<ListNode*> s(second_cnt);
        // reverse the second part
        ListNode* tmp = nullptr;
        fast = slow->next;
        for (int i=0; i<second_cnt; i++) {
            s[i] = fast;
            fast = fast->next;
        }
        // reconnect two parts
        ListNode* ptr = head;
        for (int i=second_cnt-1; i>=0; i--) {
            tmp = ptr->next;
            s[i]->next = tmp;
            ptr->next = s[i];
            ptr = tmp;
        }
        // close the end
        if (ptr!=nullptr) ptr->next = nullptr;
        return;
    }
};