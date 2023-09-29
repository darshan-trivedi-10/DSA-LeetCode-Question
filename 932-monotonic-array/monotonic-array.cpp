class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true, isDescreasing = true;
        for(int i = 1; i < nums.size(); i++){
            if(!(nums[i] >= nums[i-1])){
                isIncreasing = false;
            }
            if(!(nums[i] <= nums[i-1])){
                isDescreasing = false;
            }
        }

        return (isDescreasing || isIncreasing);
    }
};