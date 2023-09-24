class Solution {

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = dp[i+1][buy];
                if(buy == 0){
                    profit = max(profit, -fee -prices[i] + dp[i+1][1]);
                }
                if(buy == 1){
                    profit = max(profit, prices[i] + dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }

        return dp[0][0];
    }
};