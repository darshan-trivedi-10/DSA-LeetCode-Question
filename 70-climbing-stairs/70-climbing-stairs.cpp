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
        
        int oneP = 1, twoP = 1;
        
        for(int i = 2; i<=n; i++){
            int sum = oneP + twoP;
            oneP = twoP, twoP = sum;
        }
        
        return twoP;
    }
};