class Solution {
    vector<vector<int>> dp;
    
    int fm(vector<pair<int, int>>& arr, int idx, int ew) {
        if (ew <= 0) {
            return 0;
        }
        
        if (idx >= arr.size()) {    
            return 1000000000;
        }
        
        if (dp[idx][ew] != -1) {
            return dp[idx][ew];
        }
        int nT =  arr[idx].first + fm(arr, idx + 1, ew - arr[idx].second - 1);
        int T = fm(arr, idx + 1, ew);

        return dp[idx][ew] = min(nT, T);
    }
    
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = time.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({cost[i], time[i]});
        }
        // sort(a.begin(), a.end());
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return fm(a, 0, n);
    }
};
