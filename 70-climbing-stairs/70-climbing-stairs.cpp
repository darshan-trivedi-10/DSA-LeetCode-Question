class Solution {
    
    int helper(int n, vector<int> &dp){
        if(n<=0){
            return n==0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = helper(n-1, dp) + helper(n-2,dp);
    }
    
public:
    int climbStairs(int n) {
        if(n<=0){
            return n==0;
        }
        
        vector<int> dp(n+1,-1);
        return helper(n-1, dp) + helper(n-2, dp);
    }
};