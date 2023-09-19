class Solution {

    int Helper(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1 < 0){
            return ind2 + 1;
        }
        if(ind2 < 0){
            return ind1 + 1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s1[ind1] == s2[ind2]){
            dp[ind1][ind2] = Helper(s1, s2, ind1 - 1, ind2 - 1, dp);
        }else{
            dp[ind1][ind2] = 1 + min(
                {
                    Helper(s1, s2, ind1 - 1, ind2 - 1, dp),
                    Helper(s1, s2, ind1 - 1, ind2, dp),
                    Helper(s1, s2, ind1, ind2 - 1, dp),                    
                }
            );
        }

        return dp[ind1][ind2];
    }


public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return Helper(s1,s2,n-1,m-1,dp);
    }
};