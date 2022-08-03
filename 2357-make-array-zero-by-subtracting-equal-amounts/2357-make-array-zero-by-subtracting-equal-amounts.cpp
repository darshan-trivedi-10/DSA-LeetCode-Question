class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(101,0);
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(arr[nums[i]]==0 and nums[i]!=0){
                arr[nums[i]]++;
                ans++;
            }
        }
        
        return ans;
    }
};