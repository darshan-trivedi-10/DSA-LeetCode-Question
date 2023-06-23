class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n][1001];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 1001; j++){
                dp[i][j]=1;
            }
        }
        int res = 1, diff;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                diff = nums[i] - nums[j];
                dp[i][diff + 500] = max(dp[i][diff + 500], 1 + dp[j][diff + 500]);
                res = max(res , dp[i][diff + 500]);
            }
        }
        return res;
    }
};