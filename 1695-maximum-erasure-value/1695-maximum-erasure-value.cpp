class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0,sum=0,res=0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            if(mp[nums[j]]){ // nums[j] is already there in the window
                while(mp[nums[j]]){ // until the occurrence of nums[j] becomes 0, reduce the window from front
                    mp[nums[i]]--;
                    sum-=nums[i];
                    i++;
                }
            }
            else{ // nums[j] is not there in the window, so put it into the window
                sum+=nums[j];
                res=max(res,sum); // update the result with maximum sum value
                mp[nums[j]]++;
                j++;
            }
        }
        return res;
    }
};