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
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return Helper(s, t, n-1, m-1, dp);
    }
};