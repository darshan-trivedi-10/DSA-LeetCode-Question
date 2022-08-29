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
        cout<<n<<" "<<m<<endl;
        if(obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        
        vector<vector<long>> dp(n+1, vector<long>(m+1,0));
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }else{
                    if(i==n-1 and j==m-1){
                        dp[i][j] = 1;
                    }else{
                        long long up = 0, left = 0;
                        if(i<n-1){
                          up = dp[i+1][j]; 
                        }
                        if(j<m-1){
                          left = dp[i][j+1];
                        }
                        cout<<i<<" "<<j<<" "<<obstacleGrid[i][j]<<"\n";
                        dp[i][j] = up + left;
                    }
                }
            }
        }
        
        return dp[0][0];
        
        
        // return fin/dTotalPath(obstacleGrid, dp, 0,0);
    }
};