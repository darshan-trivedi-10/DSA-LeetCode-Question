class Solution {

    bool isValid(vector<vector<int>> &matrix, int row, int col){
        int n = matrix.size();
        return (min(row, col) >= 0 && max(row, col) < n);
    }

    int pathFinder(vector<vector<int>> &matrix, vector<vector<int>> &dp, int row, int col){

        if(!isValid(matrix, row, col)){
            return INT_MAX;
        }

        if(row == matrix.size() - 1){
            return matrix[row][col];
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        return dp[row][col] = matrix[row][col] + min({pathFinder(matrix, dp, row + 1, col - 1), pathFinder(matrix, dp,row + 1, col), pathFinder(matrix, dp, row + 1, col + 1)});
    }


public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int minSum = INT_MAX;
        // int row = matrix.size();
        // vector<vector<int>> dp(row, vector<int> (row, -1));
        // for(int i = 0; i < row; i++){
            // minSum = min(minSum, pathFinder(matrix, dp, 0, i));
        // }
        // return minSum;
        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        int minPathSum = INT_MAX;

        for(int i = 0; i < n; i++){
            int currPathSum = INT_MAX;
            for(int j = 0; j < n; j++){
                if(i == 0){
                    dp[i][j] = matrix[i][j];
                    currPathSum = min(currPathSum, dp[i][j]);              
                    continue;
                }
                int top = dp[i-1][j];
                int topLeft = j > 0 ? dp[i-1][j-1] : INT_MAX;
                int topRight = j < n - 1 ? dp[i-1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({top, topLeft, topRight});  
                currPathSum = min(currPathSum, dp[i][j]);              
            }
            minPathSum = currPathSum;
        }

        return minPathSum;
    }
};