class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int size = nums.size();
        unordered_map<int,int> mpp;
        int totalSubarray = 0, sum = 0;
        mpp[sum] = 1;
        for(int ele : nums){
            sum += ele;
            if(mpp.find(sum - k) != mpp.end()){
                totalSubarray += mpp[sum - k];
            }
            mpp[sum]++;
            
        }

        return totalSubarray;
    }
};