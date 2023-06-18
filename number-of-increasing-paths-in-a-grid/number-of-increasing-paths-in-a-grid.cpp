class Solution {

    int mod = 1000000000 + 7;

    bool isValid(int i, int j, int n, int m){
        return (i < n && i >= 0) && (j < m && j >= 0);
    }
    
    int helper(vector<vector<int>> &grid, int i, int j, int last, vector<vector<int>> &dp){
        int n = grid.size(), m = grid[0].size();

        if(!isValid(i , j, n, m) ){
            return 0;
        }

        int currEle = grid[i][j];

        if(currEle <= last){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int dx[] = {-1,1,0 ,0};
        int dy[] = {0,0,1,-1};

        int count = 1;
        for(int k = 0; k < 4; k++){
            int nx = i + dx[k], ny = j + dy[k];
            if(isValid(nx, ny, n, m)){
                count = (count + helper(grid, nx, ny, currEle, dp))%mod;
            }
        }

        return dp[i][j] = count;
    }


public:
    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans =(ans + helper(grid, i, j, -1, dp))%mod;
            }
        }

        return (ans%mod);
    }
};