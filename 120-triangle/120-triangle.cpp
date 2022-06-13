class Solution {
    int findMinPath(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i, int j) {
        int n = triangle.size(), m = triangle[0].size();
        if (i == n - 1)
        {
            return triangle[i][j];
        }

        if (dp[i][j] != INT_MIN)
        {
            return dp[i][j];
        }

        int bottom = findMinPath(triangle, dp, i + 1, j);
        int bottomNext = findMinPath(triangle, dp, i + 1, j + 1);

        return dp[i][j] = triangle[i][j] + min(bottom, bottomNext);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int> (n, INT_MIN));
        return findMinPath(triangle, dp, 0, 0);
    }
};