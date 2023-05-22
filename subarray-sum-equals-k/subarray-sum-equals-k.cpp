class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mpp;
        int sum = 0;
        mpp[sum] = 1;
        
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if(mpp.find(sum-target) != mpp.end()){
                ans += mpp[sum-target];
            }
            mpp[sum]++;
        }
        
        return ans;
    }
};