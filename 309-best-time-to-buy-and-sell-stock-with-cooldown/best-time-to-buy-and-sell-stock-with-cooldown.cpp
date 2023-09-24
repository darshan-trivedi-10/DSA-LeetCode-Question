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
        vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = dp[i+1][buy];
                if(buy == 0){
                    profit = max(profit, -prices[i] + dp[i+1][1]);
                }
                if(buy == 1){
                    profit = max(profit, prices[i] + dp[i+2][0]);
                }
                dp[i][buy] = profit;
            }
        }

        return dp[0][0];
    }
};