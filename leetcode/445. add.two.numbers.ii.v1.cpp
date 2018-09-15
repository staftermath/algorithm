//
// Created by gwengww on 9/15/18.
// 36ms 45.76%
// time O(n)
// space O(n)
// recursive method might be quicker but might incur stackoverflow?

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
        int length1 = 0, length2 = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p1 != nullptr) {
            p1 = p1->next;
            length1++;
        }
        while (p2 != nullptr) {
            p2 = p2->next;
            length2++;
        }
        // cout << "l1 length " << length1 << " l2 length " << length2 << endl;
        if (length1 == 0) return l2;
        if (length2 == 0) return l1;
        if (length1 < length2) {
            int tmp = length1;
            length1 = length2;
            length2 = tmp;
            swap(l1, l2);
        }
        deque<int> dq;
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;

        while (length1 > length2) {
            // cout << l1->val << endl;
            dq.push_back(l1->val);
            if (l1->val != 9)  {
                while (!dq.empty()) {
                    ptr->next = new ListNode(dq.front());
                    dq.pop_front();
                    ptr = ptr->next;
                }
            }
            length1--;
            l1 = l1->next;
        }
        while (length1 > 0) {
            dq.push_back(l1->val + l2->val);

            if (dq.back() != 9) ptr = attach_list(dq, ptr);
            l1 = l1->next;
            l2 = l2->next;
            length1--;
        }
        ptr = attach_list(dq, ptr);
        return (result->val == 0)? result->next: result;

    }

    ListNode* attach_list(deque<int>& dq, ListNode* ptr) {
        if (dq.empty()) return ptr;
        int a = 0, r;
        ListNode* tmp_list=nullptr;
        ListNode* tail=nullptr;
        while (!dq.empty()) {
            r = (dq.back()+a)%10;
            a = (dq.back()+a)/10;
            // reconstruct detached list
            ListNode* head = new ListNode(r);
            head->next = tmp_list;
            tmp_list = head;
            dq.pop_back();
        }
        if (a == 1) {
            ptr->val+=a;
        }
        ptr->next = tmp_list;
        while (ptr->next != nullptr) ptr = ptr->next;
        return ptr;
    }
};