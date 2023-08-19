class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        int profit = 0, minVal = INT_MAX;
        for(int i = 0; i < n; i++){
            minVal = min(minVal, prices[i]);
            profit = max(profit, prices[i] - minVal);
        }

        return profit;
    }
};
