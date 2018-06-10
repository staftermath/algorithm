//
// Created by gwengww on 6/9/18.
// beat 47.83%
// O(NlogN)

class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> &points) {
        // Write your code here
        if (points.size()<=1) return true;
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b){
                 return a[1] < b[1] || (a[1]==b[1] && a[0]<=b[0]);
             });
        // for (auto v: points) {
        //     cout << "[" << v[0] << "," << v[1] << "]," << flush;
        // }
        // cout << endl;
        int start=0, end=0;
        get_same_x_axis(points, start, end);
        bool result = true;
        double y=(points[start][0]+points[end][0])/2.0;
        while (end < points.size()) {
            // cout << "vertical starts from " << start << " to " << end << endl;
            result = get_y_axis(points, start, end, y);
            // cout << "y is now " << y << endl;
            if (not result) return false;
            start=end+1;
            end=start;
            get_same_x_axis(points, start, end);
        }
        return true;
    }
    bool get_y_axis(vector<vector<int>>& points, int start, int end, double& y) {
        while (start <= end) {
            while (start < end && points[start+1][0] == points[start][0]) start++;
            while (end > start && points[end-1][0] == points[end][0]) end--;
            if  ((points[start][0]+points[end][0])/2.0 != y) return false;
            start++;
            end--;
        }
        return true;
    }

    void get_same_x_axis(vector<vector<int>>& points, int& start, int& end) {
        while (end<points.size()-1&&points[end+1][1]==points[end][1]) end++;
    }

};