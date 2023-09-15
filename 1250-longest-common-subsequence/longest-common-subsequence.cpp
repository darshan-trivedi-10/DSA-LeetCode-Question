class Solution {

    int Helper(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){

        if(i == text1.size() || j == text2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int taken = 0, notTaken = 0;
        if(text1[i] == text2[j]){
            taken = 1 + Helper(text1, text2, i + 1, j + 1, dp);
        }
        notTaken = max(
            Helper(text1, text2, i + 1, j, dp), 
            Helper(text1, text2,  i, j + 1, dp)
        );
        
        return dp[i][j] = max(taken, notTaken);
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size(), j = text2.size();
        vector<vector<int>> dp(i, vector<int> (j, -1));
        // return lcsUtil(text1, text2, i - 1, j - 1, dp);
        return Helper(text1, text2, 0, 0, dp);
    }
};