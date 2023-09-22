class Solution {

    int findMaxProfit(vector<int> &prices, int index, int isStockBuy, vector<vector<int>> &dp){
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][isStockBuy] != -1){
            return dp[index][isStockBuy];
        }

        int profit = findMaxProfit(prices, index + 1, isStockBuy, dp);
        if(isStockBuy == 0){
            profit = max(profit, -prices[index] + findMaxProfit(prices, index + 1, 1, dp));
        }else{
            profit = max(
                profit,
                prices[index] + findMaxProfit(prices, index + 1, 0, dp)
            );
                  
        }
        return dp[index][isStockBuy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return findMaxProfit(prices, 0, 0, dp);    
    }
}; 