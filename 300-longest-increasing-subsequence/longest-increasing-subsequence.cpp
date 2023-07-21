class Solution {

    int helper(vector<int> &nums, vector<vector<int>> &dp, int idx, int lastIdx){
        if(idx == nums.size()){
            return 0;
        }

        if(dp[idx][lastIdx + 1] != -1){
            return dp[idx][lastIdx + 1];
        }

        int len = helper(nums, dp, idx + 1, lastIdx);
        if(lastIdx == -1 || nums[idx] > nums[lastIdx]){
            len = max(len, 1 + helper(nums, dp, idx + 1, idx));
        }

        return dp[idx][lastIdx + 1] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size + 1, -1));
        return helper(nums, dp, 0, -1);
    }
};