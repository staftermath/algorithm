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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        p = head;
        res = 0;
    }

    /** Returns a random node's value. */
    int getRandom() {
        count = 1;
        ListNode* temp = p;
        if (count == 1) {res=temp->val;}
        while (temp->next != nullptr) {
            count++;
            temp=temp->next;
            int rnd = rand() % count;
            if (rnd == count-1) {
                res=temp->val;
            }
        }
        return res;
    }
private:
    int count;
    int res;
    ListNode* p;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */