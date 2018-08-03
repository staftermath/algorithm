//
// Created by gwengww on 8/2/18.
// 4ms 98.78%
// time O(n)
// space O(1)

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        string::iterator head=s.begin();
        while (head<s.end() && *head == ' ') s.erase(head);
        string::iterator tail = head;
        bool search_char = false;
        while (tail < s.end()) {
            if (*tail == ' ') {
                if (!search_char) {
                    // find end of word
                    search_char = true;
                    reverse(head, tail);
                    head=tail;
                } else {
                    if (head != tail) s.erase(tail);
                        // looping over spaces
                    else tail++;
                }
            } else {
                if (!search_char) {
                    // looping over words
                    tail++;
                } else {
                    // found starting word
                    head = tail;
                    search_char = false;
                }
            }
        }
        if (search_char) {
            // looping over space
            s.erase(head);
        } else {
            reverse(head, tail);
        }

    }
};