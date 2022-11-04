class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1){
                return true;
            }
        }
        
        return false;
    }
};