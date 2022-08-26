class Solution {
    
    int robMax(vector<int>& nums, int s,int e) {
        if(s<0 and s>= nums.size() and e>nums.size()){
            return 0;
        }
        
        int prev = nums[s], prev2;
        for(int i = s+1; i<e; i++){
            // dp[i] = max(dp[i-1], nums[i]);
            int curr = max(prev, nums[i]);
            if(i>1){ 
                // dp[i] = max(dp[i-2] + nums[i], dp[i]);
                curr = max(prev2 + nums[i], curr);
            }
            
            prev2 = prev;
            prev = curr;
        }
        cout<<prev<<" ";
        return prev;
    }
    
public:
    int rob(vector<int>& nums) { 
        int n = nums.size();
        
        int ans = robMax(nums, 0, n-1);
        if(nums.size()>1){
            ans = max(ans,robMax(nums, 1, n));
        }
        
        return ans;
    }
};