class Solution {

    // abce
    // bcd

    int Helper(string &s, string &t, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind2 < 0){
            return 1;
        }
        if(ind1 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s[ind1] == t[ind2]){
            int leaveOne = Helper(s, t, ind1 - 1, ind2 - 1, dp);
            int stay = Helper(s, t, ind1 - 1, ind2, dp);

            return dp[ind1][ind2] = leaveOne + stay;
        }else{
            return dp[ind1][ind2] = Helper(s, t, ind1 - 1, ind2, dp);
        }  
    }


public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size(), M = 1e9 + 7;
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return Helper(s, t, n-1, m-1, dp);

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        } 

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%M;
                }else{
                    dp[i][j] = dp[i-1][j]%M;
                }
            }
        }

        return dp[n][m]%M;
    }
};