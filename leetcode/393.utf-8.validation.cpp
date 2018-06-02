//
// Created by gwengww on 6/2/18.
// beat 97.47%

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for (int i=0; i<data.size();) {
            if (data[i] >= 256 || data[i] < 0) return false;
            int size = get_utf_size(data[i]);
            // cout << "size is " << size << endl;
            if (size == 0) return false;
            while (size-- > 1) {
                if (++i>=data.size() || !is_valid(data[i])) return false;
                // cout << "now at " << data[i] << ". remaining size: " << size << endl;
            }
            // cout << "size is now " << size << endl;
            i++;
        }
        return true;

    }
private:
    int get_utf_size(int x) {
        if ((x & 1<<7) == 0) return 1;
        if ((x & 1<<6) == 0) return 0;
        if ((x & 1<<5) == 0) return 2;
        if ((x & 1<<4) == 0) return 3;
        if ((x & 1<<3) == 0) return 4;
        return 0;
    }
    int is_valid(int x) {
        if (x< 2<<6 || x > 256) return false;
        else return true;
    }
};