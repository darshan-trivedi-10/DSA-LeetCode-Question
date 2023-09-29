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
        
        vector<vector<int>> dp(m + 1, vector<int> (m + 1, -1));
        return Helper(1, m, cuts, dp);
    }
};