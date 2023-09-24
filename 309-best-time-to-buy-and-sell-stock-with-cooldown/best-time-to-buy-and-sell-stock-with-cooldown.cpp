class Solution {
    int Helper(vector<int> &prices, int index, int buy, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = Helper(prices, index + 1, buy, dp);
        if(buy == 0){
            profit = max(profit, -prices[index] + Helper(prices, index + 1, 1, dp));
        }

        if(buy == 1){
            profit = max(profit, prices[index] + Helper(prices, index + 2, 0, dp));
        }

        return dp[index][buy] = profit;
    }


public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return Helper(prices, 0, 0, dp);
    }
};