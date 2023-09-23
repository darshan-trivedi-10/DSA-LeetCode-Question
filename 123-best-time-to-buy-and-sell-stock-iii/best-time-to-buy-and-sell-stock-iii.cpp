class Solution {

    int Helper(vector<int> &prices, int index, int buy, int k, vector<vector<vector<int>>> &dp){
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][buy][k] != -1){
            return dp[index][buy][k];
        }

        int profit =  Helper(prices, index + 1, buy, k, dp);
        if(buy == 0 && k > 0){
            // buy
            profit = max(profit, -prices[index] + Helper(prices, index + 1, 1, k - 1, dp));
        }

        if(buy ==  1){
            // sell
            profit = max(profit, prices[index] + Helper(prices, index, 0, k, dp));
        }

        return dp[index][buy][k] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2,vector<int>(3,-1)));
        return Helper(prices, 0, 0, 2, dp);
    }
};