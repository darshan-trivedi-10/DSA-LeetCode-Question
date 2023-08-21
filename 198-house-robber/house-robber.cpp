class Solution {

    int Helper(int idx, vector<int> &nums, vector<int> &dp){
        if(idx >= nums.size()){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int take = nums[idx] + Helper(idx + 2, nums, dp);
        int nonTake = Helper(idx + 1, nums, dp);

        return dp[idx] = max(take, nonTake);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], dp[i-1]);
            if(i > 1){
                dp[i] = max(dp[i], nums[i] + dp[i-2]);
            }
        }

        return dp[nums.size() - 1];      
    }
};