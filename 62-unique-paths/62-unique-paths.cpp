
class Solution
{
    int findPath(vector<vector<int>> &dp, int m, int n, int i, int j)
    {
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }
        if (i >= n || j >= m || i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = findPath(dp, m, n, i, j + 1);
        int bottom = findPath(dp, m, n, i + 1, j);
        return dp[i][j] = right + bottom;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int totalPath = findPath(dp, m, n, 0, 0);
        return totalPath;
    }
};