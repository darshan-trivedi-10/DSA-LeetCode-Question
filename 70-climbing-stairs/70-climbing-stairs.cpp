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
        
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++){
            cout<<i<<" "<<dp[i-1]+dp[i-2]<<endl;
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};