class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        
        int left = 0, right = 0, longestArray = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == 0){
                left = right;
                right = 0;
            }else{
                right++;
            }

            longestArray = max(longestArray, left + right);
        }

        if(longestArray == size){
            longestArray--;
        }

        return longestArray;
    }
};