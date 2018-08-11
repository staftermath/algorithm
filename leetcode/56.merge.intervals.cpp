//
// Created by gwengww on 8/10/18.
// 8ms 98.35%

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int size = intervals.size();
        if (size == 0) return intervals;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        int insert_to=0, i=0;
        while (i<size) {
            // cout << "inserting to " << insert_to << ". looking at " << i << endl;
            if (intervals[i].start <= intervals[insert_to].end) {
                intervals[insert_to].end = max(intervals[i].end, intervals[insert_to].end);
            } else {
                insert_to++;
                intervals[insert_to].start = intervals[i].start;
                intervals[insert_to].end = intervals[i].end;
            }
            i++;
        }
        intervals.resize(insert_to+1);
        return intervals;
    }

};