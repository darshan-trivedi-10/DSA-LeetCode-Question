// class Solution {

//     int Helper(vector<int> &prices,vector<vector<int>> &dp, int fee, int idx, int lastBuy){
//         if(idx == prices.size()){
//             return 0;
//         }

//         if(dp[idx][lastBuy] != -1){
//             return dp[idx][lastBuy];
//         }
     
//         int maxProfit = INT_MIN;
//         if(lastBuy == 0){
//             int buy = -prices[idx] + Helper(prices, dp, fee, idx + 1, 1);
//             maxProfit = max(maxProfit, buy);
//         }else{
//             int sell = prices[idx] - fee + Helper(prices, dp, fee, idx + 1, 0);
//             maxProfit = max(maxProfit, sell);
//         }
        
//         int noBuySell = Helper(prices, dp, fee, idx + 1, lastBuy);
//         maxProfit = max(maxProfit, noBuySell);

//         dp[idx][lastBuy] = maxProfit;
//         return dp[idx][lastBuy];
//     }

// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         const int size = prices.size();
//         vector<vector<int>> dp(size,vector<int>(2, -1));
//         return Helper(prices, dp , fee , 0 , 0);
//     }
// };

class Solution {
public:
    // Time Complexity:- O(N)
    // Space Complexity:- O(1)
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n < 2)
            return 0;
        int buy = -prices[0];
        int sell = 0;
        for(int i = 1; i < n; i++) {
            int new_buy = max(buy, sell - prices[i]);    
            int new_sell = max(sell, buy + prices[i] - fee);
         
            buy = new_buy;
            sell = new_sell;
        }
        return sell;
    }
};