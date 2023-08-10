class Solution {


    int Helper(vector<vector<int>> &dp, int start, int end){
        if(start > end || start <= 0){
            return 1;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int uniqueTree = 0;
        for(int i = start; i <= end; i++){
            uniqueTree += Helper(dp, start, i - 1) * Helper(dp, i + 1, end);
        }

        return dp[start][end] = uniqueTree;
    }

public:
    int numTrees(int n) {
        if(n == 0){
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return Helper(dp, 1, n);
    }
};
