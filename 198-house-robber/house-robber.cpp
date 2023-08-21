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
        int prev1 = nums[0], prev2 = 0;

        for(int i = 1; i < nums.size(); i++){
            int notPick = prev1;
            int pick = nums[i] + (i > 1 ? prev2 : 0);
            prev2 = prev1;
            prev1 = max(pick, notPick);
        }

        return prev1;      
    }
};