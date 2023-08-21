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
        vector<int> dp(nums.size(), -1);
        return Helper(0, nums, dp);      
    }
};