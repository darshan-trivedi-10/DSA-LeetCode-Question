class Solution {
    
    int findTotalPath(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int i, int j){
        
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(i==n-1 and j==m-1){
            return 1;
        } 
        
        if(i>=n || j>=m){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int bottom = 0, right = 0;
        if(obstacleGrid[i][j]==0){
            bottom = findTotalPath(obstacleGrid, dp, i+1,j);
            right = findTotalPath(obstacleGrid, dp,i, j+1);
        }
        
        return dp[i][j] = bottom + right;   
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        if(obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return findTotalPath(obstacleGrid, dp, 0,0);
    }
};