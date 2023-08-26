class Solution {

    bool isValid(int i, int j, int n, int m){
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int pathFinder(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(!isValid(i, j, n, m)){
            return INT_MAX;
        }

        if(i == n-1 && j == m - 1){
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int leftPath = pathFinder(grid, dp, i, j + 1);
        int bottomPath = pathFinder(grid, dp, i + 1, j);

        return dp[i][j] = grid[i][j] + min(leftPath, bottomPath);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return pathFinder(grid, dp, 0, 0);
    }
};