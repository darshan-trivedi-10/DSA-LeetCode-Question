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
            profit = max(profit, -prices[index] + Helper(prices, index + 1, 1, k - 1, dp));
        }

        if(buy ==  1){
            profit = max(profit, prices[index] + Helper(prices, index, 0, k, dp));
        }

        return dp[index][buy][k] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2,vector<int>(3,-1)));
        // return Helper(prices, 0, 0, 2, dp);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int k = 0; k <= 2; k++){
                    int profit = dp[i+1][buy][k];
                    if(buy == 0 && k > 0){
                        profit = max(profit, -prices[i] + dp[i + 1][1][k - 1]);
                    }
                    
                    if(buy ==  1){
                        profit = max(profit, prices[i] + dp[i][0][k]);
                    }

                    dp[i][buy][k] = profit;
                }
            }
        }

        return dp[0][0][2];
    }
};