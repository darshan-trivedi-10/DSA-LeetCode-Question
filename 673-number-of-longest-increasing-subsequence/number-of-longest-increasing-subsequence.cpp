class Solution {

public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j] && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }else if(arr[i] > arr[j] && 1 + dp[j] == dp[i]){
                    cnt[i] += cnt[j];
                }
            }
        }

        int maxi = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(maxi == dp[i]){
                ans += cnt[i];
            }
        }

        return ans;
    }
};