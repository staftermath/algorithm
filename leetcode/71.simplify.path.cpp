//
// Created by gwengww on 5/3/18.
// beat 99.63%

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> result;
        int start = 0;
        int end = start+1;
        if (path.size() <=1) return path;
        while (start < path.size()-1) {
            if (path[end] == '/' && end == start+1) {
                start++;
                end++;
                continue;
            }
            if (path[end] != '/') {
                end++;
                continue;
            }
            string thisFolder = path.substr(start, end-start);
            if ( thisFolder == "/..") {
                if (result.size() > 0) result.pop_back();
            } else if (thisFolder != "/.") {
                result.push_back(thisFolder);
            }
            start = end;
            end++;
        }
        if (result.size() == 0) return "/";
        else {
            string result_str;
            while (!result.empty()) {
                result_str += result.front();
                result.pop_front();
            }
            return result_str;
        }
    }
};