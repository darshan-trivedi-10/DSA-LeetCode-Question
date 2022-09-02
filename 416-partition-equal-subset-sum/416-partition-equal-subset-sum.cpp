class Solution
{
    bool checkSum(vector<int> &arr, vector<vector<int>> &dp, int totalSum, int idx)
    {
        
        if (totalSum <= 0)
        {
            return totalSum==0;
        }

        if (idx >= arr.size() - 1)
        {
            return arr[idx] == totalSum;
        }

        if (dp[idx][totalSum] != -1)
        {
            return dp[idx][totalSum];
        }

        bool a = checkSum(arr, dp, totalSum, idx + 1);
        bool b = checkSum(arr, dp, totalSum - arr[idx], idx + 1);

        return dp[idx][totalSum] = a || b;
    }

public:
    bool canPartition(vector<int> &arr)
    {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (totalSum & 1)
        {
            return false;
        }
        totalSum /= 2;
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
        return checkSum(arr, dp, totalSum, 0);
    }
};