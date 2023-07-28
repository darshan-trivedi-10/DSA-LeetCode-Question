class Solution {

    int Helper(vector<int> &nums, vector<vector<int>> &dp, int left, int right){
        if(left == right){
            return nums[left];
        }

        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int leftScore = nums[left] - Helper(nums, dp,left + 1, right);
        int rightScore = nums[right] - Helper(nums,dp, left, right - 1);

        return dp[left][right] = max(leftScore, rightScore);
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp (size, vector<int>(size, -1));
        return Helper(nums, dp, 0, nums.size() - 1) >= 0;
    }
};















