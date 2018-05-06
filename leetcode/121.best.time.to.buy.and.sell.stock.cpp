//
// Created by gwengww on 5/5/18.
// beat 21.08%
// seems to be optimal solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int low = prices[0];
        int maximum = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] < low) low = prices[i];
            else {
                maximum = max(maximum, prices[i] - low);
            }
        }
        return maximum;
    }
};