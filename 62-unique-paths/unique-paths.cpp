class Solution {

    bool isValid(int i, int j, int n, int m){
        return (i < n and j < m);
    }
    
    int findPath(int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i == n - 1 and j == m - 1){
            return 1;
        }

        if(!isValid(i, j, n, m)){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = findPath(i + 1, j, n, m, dp);
        int right = findPath(i, j + 1, n, m, dp);        

        return dp[i][j] = down + right;
    }

public:
    int uniquePaths(int n, int m) {
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return findPath(0, 0, n, m, dp);

        // vector<vector<int>> dp(n, vector<int> (m, 0));

        vector<int> prev(m, 0);

        for(int i = 0; i < n; i++){
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                }
                if(i > 0){
                    curr[j] += prev[j];
                }
                if(j > 0){
                    curr[j] += curr[j-1];
                }
            }

            prev = curr;
        }

        return prev[m-1];
    }
};