//
// Created by gwengww on 6/16/18.
// 33ms 79.74%
// segment tree O(nlogn)
// must initiate val

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> results(size);
        if (size<=1) return results;
        int minimum=nums[0], maximum=nums[0];
        for (int i=0; i<size; i++) {
            maximum = max(maximum, nums[i]);
            minimum = min(minimum, nums[i]);
        }
        SegmentTree tree(minimum, maximum);
        for (int i=size-2; i>=0; i--) {
            // cout << "now at: " << i << endl;
            tree.update(nums[i+1]);
            results[i] = tree.sum(minimum, nums[i]-1);
        }
        return results;
    }
    struct SegmentTree {
        int sum(int s, int e) {
            if (s > this->end || e < this->start) return 0;
            if (s <= this->start && e >= this->end) return this->val;
            return this->left->sum(s, e) + this->right->sum(s, e);
        }
        void update(int pos) {
            if (pos < this->start && pos > this->end) return;
            this->val++;
            if (pos == this->start && pos == this->end) return;
            if (pos <= (this->start+this->end)>>1) this->left->update(pos);
            if (pos > (this->start+this->end)>>1) this->right->update(pos);
        }
        SegmentTree* left;
        SegmentTree* right;
        int start;
        int end;
        int val;
        SegmentTree(int s, int e){
            this->val = 0;
            // cout << "constructing from: " << s << " to " << e << endl;
            if (s<=e) {
                this->start = s;
                this->end = e;
            }
            if (s<e) {
                int half = (s+e)>>1;
                this->left = new SegmentTree(s, half);
                this->right = new SegmentTree(1+half, e);
            }
        }
    };

};