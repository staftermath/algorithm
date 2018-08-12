//
// Created by gwengww on 8/12/18.
// 20ms 99.36%
// time O(n)
// space O(1)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int size = s.size(), p_size = p.size(), total_count = p_size;
        if (size == 0 || p_size == 0) return {};
        vector<int> result;
        vector<int> counts(26, -1);
        int index;
        for (auto c: p) {
            index = c-'a';
            (counts[index] == -1)? counts[index] = 1: counts[index]++;
        }
        vector<int> max_counts(counts);
        int head=0, tail=head;
        while (tail < size) {
            index = s[tail]-'a';
            if (counts[index] == -1) {
                // not in string p
                tail++;
                head=tail;
                counts = max_counts;
                total_count = p_size;
            } else {
                if (counts[index] > 0) {
                    counts[index]--;
                    total_count--;
                } else if (s[tail] == s[head]) {
                    head++;
                } else {
                    while (s[tail] != s[head]) {
                        counts[s[head]-'a']++;
                        head++;
                        total_count++;
                    }
                    // no need to reduce tail char count
                    head++;
                }
                if (total_count == 0) {
                    result.push_back(head);
                }
                tail++;
            }
        }
        return result;

    }
};