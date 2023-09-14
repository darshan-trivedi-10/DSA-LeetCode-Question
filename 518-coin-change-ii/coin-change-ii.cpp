class Solution {

    int Helper(vector<int> &coins, int index, int amount, vector<vector<int>> &dp){
        if(index == 0){
            return amount%coins[index] == 0;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        int notTaken = Helper(coins, index - 1, amount, dp);
        int taken = 0;
        if(coins[index] <= amount){
            taken = Helper(coins, index, amount - coins[index], dp);
        }

        return dp[index][amount] = taken + notTaken;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return Helper(coins, n - 1, amount, dp);
    }
};