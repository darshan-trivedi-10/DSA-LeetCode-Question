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
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;
        int prev2 = 1, prev1 = 1;

        for(int i = 2; i <= n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};