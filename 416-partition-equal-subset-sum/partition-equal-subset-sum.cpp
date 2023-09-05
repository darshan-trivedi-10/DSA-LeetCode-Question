class Solution {

    bool partitionHelper(vector<int> &nums, vector<vector<int>> &dp,int index, int sum){
        if(index == nums.size() || sum <= 0){
            return sum == 0;
        }

        if(dp[index][sum] != -1){
            return dp[index][sum];
        }

        bool take = partitionHelper(nums, dp, index + 1, sum - nums[index]);
        bool notTake = partitionHelper(nums, dp, index + 1, sum);

        return dp[index][sum] = take || notTake;
    }


public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1){
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int> ((sum/2) + 1, -1));
        return partitionHelper(nums, dp, 0, sum/2);
    }
};