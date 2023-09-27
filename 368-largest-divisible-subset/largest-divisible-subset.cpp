class Solution {

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> hash(n, 1);

        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int prev_index = 0; prev_index <= i-1; prev_index++){
                if(
                    nums[i]%nums[prev_index] == 0 && 
                    1 + dp[prev_index] > dp[i]
                ){
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }

        int ans = -1;
        int lastIndex = -1;

        for(int i = 0; i <= n-1; i++){
            if(dp[i] > ans){
                ans = dp[i];
                lastIndex = i;
            }
        }

        vector<int> subset;
        subset.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            subset.push_back(nums[lastIndex]);
        }

        reverse(subset.begin(), subset.end());
        return subset;
    }
};