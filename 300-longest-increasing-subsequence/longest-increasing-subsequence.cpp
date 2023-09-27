class Solution {
    int Helper(vector<int> &nums, int index, int prevIndex, vector<vector<int>> &dp){
        if(index == nums.size()){
            return 0;
        }

        if(dp[index][prevIndex + 1]){
            return dp[index][prevIndex + 1];
        }

        int len = Helper(nums, index + 1, prevIndex, dp), take = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            len = max(len, 1 + Helper(nums, index + 1, index, dp));
        }

        return dp[index][prevIndex + 1] = len;
    }

public:
    int lengthOfLIS(vector<int>& arr) {
      int n = arr.size();
      vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

      for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= -1; j--) {
          int len = dp[i + 1][j + 1];
          if (j == -1 || arr[i] > arr[j]) {
            len = max(len, 1 + dp[i + 1][i + 1]);
          }
          dp[i][j + 1] = len;
        }
      }
        
      return dp[0][0];
    }
};