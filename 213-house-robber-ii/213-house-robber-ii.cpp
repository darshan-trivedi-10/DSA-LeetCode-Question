class Solution {
    
    int robMax(vector<int> &nums, vector<pair<int,bool>> &dp, int idx, int n, bool first){
        cout<<idx<<" "<<first<<endl;
        if(idx>=n || (idx==n-1 and first==true)){
            return 0;
        }
        
        if(dp[idx].first != -1 and dp[idx].second==first){
            return dp[idx].first;
        }
        
        cout<<1<<endl;
        int firstHouseRob = robMax(nums,dp,idx+2,n, (idx==0?true:first)) + nums[idx];
        cout<<2<<endl;
        int secondHouseRob = robMax(nums,dp,idx+1,n, first);
        dp[idx].first = max(firstHouseRob,secondHouseRob), dp[idx].second = first;
        
        return dp[idx].first;
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int,bool>> dp(n, {-1,0});
        return robMax(nums, dp, 0, n, false);        
    }
};