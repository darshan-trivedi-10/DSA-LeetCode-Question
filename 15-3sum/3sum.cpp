class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
       
        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int j = i + 1, k = n - 1;
            int requireSum = 0 - nums[i];
            while(j < k){
                int currSum = nums[j] + nums[k];
                if(currSum == requireSum){
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while(j < k && nums[j] == nums[j - 1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k + 1]){
                        k--;
                    }
                }else if(currSum > requireSum){
                    k--;
                }else{
                    // currSum < requireSum
                    j++;
                }
            }            
        }

        return triplets;
    }
};