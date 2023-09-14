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
        // vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        // return Helper(coins, n - 1, amount, dp);

        vector<vector<int>> dp(n, vector<int> (amount + 1, 0));
        for(int i = 0; i <= amount; i++){
            if(i%coins[0] == 0){
                dp[0][i] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int notTaken = dp[i-1][j];
                int taken = 0;
                if(coins[i] <= j){
                    taken = dp[i][j - coins[i]];
                }

                dp[i][j] = taken + notTaken;
            }
        }

        return dp[n-1][amount];
    }
};