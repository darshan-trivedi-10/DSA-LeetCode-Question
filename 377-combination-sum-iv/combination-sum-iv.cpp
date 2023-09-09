class Solution {
    int Helper(vector<int> &nums, vector<int> &dp, int target, int n){
        if(target <= 0){
            return target == 0;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= target){
                ans += Helper(nums, dp, target - nums[i], n);
            }
        }

        return dp[target] = ans;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<int> dp(target + 1, -1);
        return Helper(nums, dp, target, n);
    }
};