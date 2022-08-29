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
        
        int bottom = findMinSumPath(triangle, dp, i+1, j);
        int bottomSide = findMinSumPath(triangle, dp, i+1, j+1);
        
        return dp[i][j] = triangle[i][j] + min(bottom, bottomSide);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return findMinSumPath(triangle, dp, 0, 0);
    }
};