class Solution {
    int dp[51][51][51];
    int mod = (1e9+7);
    
    bool isOutofGrid(int n, int m, int row, int col){
        return !(row>=0 and col>=0 and row<n and col<m);
    }
    
    int Helper(int n, int m, int move, int row, int col){
        if(isOutofGrid(n, m, row, col)){
            return 1;
        }
        
        if(move<=0){
            return 0;
        }
        
        if(dp[row][col][move] != -1){
            return dp[row][col][move];
        }
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        int validPath = 0;
        
        for(int i = 0; i<4; i++){
            int nx = dx[i] + row;
            int ny = dy[i] + col;
            validPath = (validPath + Helper(n,m,move-1,nx,ny))%mod;
        }
        
        return dp[row][col][move] = validPath;
    }
    
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        return Helper(n, m, maxMove, startRow, startColumn);
    }
};