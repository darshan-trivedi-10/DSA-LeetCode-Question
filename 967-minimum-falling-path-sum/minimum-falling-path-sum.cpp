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
        
        // vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        vector<int> prev(n, INT_MAX);
        int minPathSum = INT_MAX;

        for(int i = 0; i < n; i++){
            int currPathSum = INT_MAX;
            vector<int> curr(n, INT_MAX);
            for(int j = 0; j < n; j++){
                if(i == 0){
                    curr[j] = matrix[i][j];
                    currPathSum = min(currPathSum, curr[j]);              
                    continue;
                }
                int top = prev[j];
                int topLeft = j > 0 ? prev[j-1] : INT_MAX;
                int topRight = j < n - 1 ? prev[j+1] : INT_MAX;
                curr[j] = matrix[i][j] +  min({top, topLeft, topRight});  
                currPathSum = min(currPathSum, curr[j]);   
            }

            prev = curr;
            minPathSum = currPathSum;
        }

        return minPathSum;
    }
};