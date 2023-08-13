class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]] = i;
        }

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int ele = target - nums[i];
            if(mpp.find(ele) != mpp.end() && mpp[ele] != i){
                ans.push_back(i);
                ans.push_back(mpp[ele]);
                break;
            }
        }

        return ans;
    }
};