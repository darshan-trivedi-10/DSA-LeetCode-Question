class Solution {
    
    int robMax(vector<int> &nums, vector<int> &dp, int idx, int n){
        if(idx>=n){ 
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int firstHouseRob = robMax(nums,dp,idx+2,n) + nums[idx];
        int secondHouseRob = robMax(nums,dp,idx+1,n);
        
        return dp[idx] = max(firstHouseRob,secondHouseRob);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, -1);
        return robMax(nums, dp, 0, n);
    }
};