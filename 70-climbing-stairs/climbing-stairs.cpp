class Solution {
    int climber(int n, vector<int> &dp){
        if(n <= 0){
            return n == 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = climber(n - 1, dp) + climber(n - 2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climber(n, dp);
    }
};