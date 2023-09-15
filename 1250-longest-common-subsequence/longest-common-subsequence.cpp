class Solution {

    int Helper(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){

        if(i == text1.size() || j == text2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return -1;
        }

        int taken = 0, notTaken = 0;
        if(text1[i] == text2[j]){
            taken = 1 + Helper(text1, text2, i + 1, j + 1, dp);
        }else{
            notTaken = max(
                Helper(text1, text2, i + 1, j, dp), 
                Helper(text1, text2,  i, j + 1, dp)
            );
        }

        return dp[i][j] = max(taken, notTaken);
    }

    int lcsUtil(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){

    if(ind1<0 || ind2<0)
        return 0;
        
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1,s2,ind1-1,ind2-1,dp);
    
    else 
        return dp[ind1][ind2] = 0 + max(lcsUtil(s1,s2,ind1,ind2-1,dp),lcsUtil
       (s1,s2,ind1-1,ind2,dp));
   
}

public:
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size(), j = text2.size();
        vector<vector<int>> dp(i, vector<int> (j, -1));
        return lcsUtil(text1, text2, i - 1, j - 1, dp);
        // return Helper(text1, text2, 0, 0, dp);
    }
};