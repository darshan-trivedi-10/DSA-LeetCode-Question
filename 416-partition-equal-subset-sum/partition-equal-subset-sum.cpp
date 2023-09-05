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
        sum /= 2;

        int n = nums.size();
        vector<vector<bool>> dp(nums.size(), vector<bool> (sum + 1, false));
        // index, sum
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= sum; j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i] <= j){
                    take = dp[i-1][j - nums[i]];
                }

                dp[i][j] = notTake || take;
            }
        }

        return dp[n-1][sum];






    }
};