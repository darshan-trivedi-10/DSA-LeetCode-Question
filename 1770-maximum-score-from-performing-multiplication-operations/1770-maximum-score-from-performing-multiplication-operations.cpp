class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int n, int j, vector<int> &nums, vector<int> &multipliers){
        
        if (j == multipliers.size()) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        
        // Left Side
        int left = solve(i + 1, n, j + 1, nums, multipliers) + (nums[i] * multipliers[j]);
        
        // Right Side
        int right = solve(i, n, j + 1, nums, multipliers) + (nums[(n - 1) - (j - i)] * multipliers[j]);
        
        return dp[i][j] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {   
        int n = nums.size(), m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, n, 0, nums, multipliers);
    }
};
