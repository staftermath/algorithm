//
// Created by gwengww on 7/11/18.
// 16ms 99.98%
// time O(log(K)*M) ?
// space O(1) ?

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        return mergeKLists(lists, 0, lists.size()-1);
    }

    ListNode* merge2Lists(ListNode* list_a, ListNode* list_b) {
        if (list_a == nullptr) return list_b;
        if (list_b == nullptr) return list_a;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (true) {
            if (list_a == nullptr) {
                tail->next = list_b;
                break;
            } else if (list_b == nullptr) {
                tail->next = list_a;
                break;
            } else if (list_a->val <= list_b->val){
                tail->next = list_a;
                list_a = list_a->next;
            } else {
                tail->next = list_b;
                list_b = list_b->next;
            }
            tail = tail->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int from, int to) {
        if (from+1 == to) {
            return merge2Lists(lists[from], lists[to]);
        } else if (from == to) {
            return lists[from];
        } else {
            int mid = (from+to)/2;
            return merge2Lists(mergeKLists(lists, from, mid), mergeKLists(lists, mid+1, to));
        }

    }
};