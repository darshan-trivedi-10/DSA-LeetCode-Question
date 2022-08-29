class Solution {
    
    bool isValid(int i, int j, int n, int m){
        return i<n and i>=0 and j<m and j>=0;
    }
    
    int findMinSumPath(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i==n-1 and j==m-1){
            return grid[i][j];
        }
        
        if(!isValid(i, j, n, m)){ 
            return INT_MAX;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = findMinSumPath(grid, dp, i+1, j);
        int right = findMinSumPath(grid, dp, i, j+1);
                
        return dp[i][j] = min(down, right) + grid[i][j];
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i==n-1 and j==m-1){
                    dp[i][j] = grid[i][j];
                }else{
                    int up = INT_MAX, down = INT_MAX;
                    if(i<n-1){
                        up = dp[i+1][j];
                    }
                    if(j<m-1){
                        down = dp[i][j+1];
                    }
                    
                    dp[i][j] = min(up, down) + grid[i][j];
                }
                
            }
        }
        
        return dp[0][0];
        
        // return findMinSumPath(grid, dp, 0, 0);
    }
};