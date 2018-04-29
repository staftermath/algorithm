//
// Created by gwengww on 4/29/18.
//

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> hash;
        if (head == nullptr) return nullptr;
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* newhead = dummy;
        while (head != nullptr) {
            RandomListNode* temp = new RandomListNode(head->label);
            newhead->next = temp;
            temp->random = head->random;
            hash[head] = temp;
            head = head->next;
            newhead = newhead->next;
        }
        newhead = dummy->next;
        while (newhead!= nullptr) {
            if (newhead->random != nullptr){
                newhead->random = hash[newhead->random];
            }
            newhead = newhead->next;
        }
        return dummy->next;
    }
};