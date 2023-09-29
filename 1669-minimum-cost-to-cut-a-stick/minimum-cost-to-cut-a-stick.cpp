class Solution {

    int Helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int res = INT_MAX;
        for(int idx = i; idx <= j; idx++){
            int cost = cuts[j + 1] - cuts[i - 1] + 
                    Helper(i, idx - 1, cuts, dp) + 
                    Helper(idx + 1, j, cuts, dp);
            res = min(res, cost);
        }

        return dp[i][j] = res;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(begin(cuts), 0);

        sort(cuts.begin(), cuts.end());
        
        // vector<vector<int>> dp(m + 1, vector<int> (m + 1, -1));
        // return Helper(1, m, cuts, dp);
        
        vector<vector<int>> dp(m + 2, vector<int> (m + 2, 0));

        for(int i = m; i >= 1; i--){
            for(int j = 1; j <= m; j++){
                if(i > j){
                    continue;
                }
                int mini = INT_MAX;
                for(int ind = i; ind <= j; ind++){
                    int ans = cuts[j+1] - cuts[i-1] + 
                            dp[i][ind-1] + dp[ind + 1][j];
                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][m];
    }
};