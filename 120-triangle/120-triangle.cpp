class Solution {
    
    int findMinSumPath(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i, int j){
        int n = triangle.size(), m = triangle[0].size();
        
        if(j>=n){
            return INT_MAX;
        } 
        
        if(i==n-1){
            return triangle[i][j];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = findMinSumPath(triangle, dp, i+1, j);
        int diagonal = findMinSumPath(triangle, dp, i+1, j+1);
        
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i = n-1; i>=0; i--){
            for(int j = triangle[i].size()-1; j>=0; j--){
                if(i==n-1){
                    dp[i][j] = triangle[i][j];
                }else{
                    int down = dp[i+1][j], diagonal = dp[i+1][j+1];
                    dp[i][j] = triangle[i][j] + min(down, diagonal);
                }
            }
        }
        
        return dp[0][0];
        
        
        // return findMinSumPath(triangle, dp, 0, 0);
    }
};