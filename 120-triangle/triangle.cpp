class Solution {
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        vector<vector<int>> dp(row);
        int bottomMin = INT_MAX;
        for(int i = 0; i < row; i++){
            col = triangle[i].size();
            dp[i].resize(col, INT_MAX);
            int currMin = INT_MAX;
            for(int j = 0; j < col; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = triangle[i][j];
                }
                if(i > 0 && j < col - 1){
                    dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i - 1][j]);
                }
                if(j > 0){
                    dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i - 1][j - 1]);
                }
                currMin = min(currMin, dp[i][j]);
            }
            bottomMin = currMin;
        }

        return bottomMin;
    }
};