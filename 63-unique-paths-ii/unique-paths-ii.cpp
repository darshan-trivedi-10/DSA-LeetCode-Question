class Solution {

    bool isValid(int i, int j, int n, int m){
        return (i >= 0 && j >=0 && i < n && j < m);
    }

    int findPath(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(!isValid(i, j, n, m)){
            return 0;
        }

        if(obstacleGrid[i][j] == 1){
            return 0;
        }

        if(i == n - 1 && j == m - 1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = findPath(i + 1, j, n, m, obstacleGrid, dp);
        int right = findPath(i, j + 1, n, m, obstacleGrid, dp);

        return dp[i][j] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        return findPath(0, 0, n, m, obstacleGrid, dp);
    }
};