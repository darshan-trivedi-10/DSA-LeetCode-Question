class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k == 0)
            return 0;
        if (prices.size() == 0 || prices.size() == 1)
            return 0;

        vector<vector<int>> dp(k + 1, vector<int>(prices.size()));
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 0;
                else
                {
                    int x;
                    int mx = INT_MIN;
                    for (int k = 0; k < j; k++)
                    {
                        x = prices[j] - prices[k] + dp[i - 1][k];
                        mx = max(x, mx);
                    }
                    dp[i][j] = max(dp[i][j - 1], mx);
                }
            }
        }
        return dp[dp.size() - 1][prices.size() - 1];
    }
};