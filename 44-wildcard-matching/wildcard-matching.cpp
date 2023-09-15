class Solution {
public:
    // i for pattern, j for text
    bool Helper(string &pattern, string &text,  int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0){
            return true;
        }
        if(i < 0 && j >= 0){
            return false;
        }
        if(i >= 0 && j < 0){
            for(int k = 0; k <= i; k++){
                if(pattern[k] != '*'){
                    return false;
                }
            }

            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(pattern[i] == text[j] || pattern[i] == '?'){
            return dp[i][j] = Helper(pattern, text, i - 1, j - 1, dp);
        }

        if(pattern[i] == '*'){
            return dp[i][j] = Helper(pattern, text, i - 1, j, dp) || Helper(pattern, text, i, j - 1, dp);
        }

        return dp[i][j] = false;
    }
    
 
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return Helper(p, s, p.size() - 1, s.size() - 1, dp);
    }
};