//
// Created by gwengww on 8/15/18.
// 0ms 100%
// worst case O(n): prime
// best case O(log(n)): power of 2

class Solution {
public:
    int minSteps(int n) {
        vector<pair<int, int>> prime;
        int power;
        for (int i=2; i<=n;i++) {
            power=0;
            while (n%i==0) {
                n/=i;
                power++;
            }
            if (power > 0) {
                prime.emplace_back(make_pair(i, power));
            }
        }
        int result = 0;
        for (int i=0; i<prime.size(); i++) {
            // cout << prime[i].first << ":" << prime[i].second << endl;
            result += prime[i].first*prime[i].second;
        }
        return result;
    }
};