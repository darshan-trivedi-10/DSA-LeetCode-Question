class Solution {

    int Helper(vector<int> &nums, int start, int end){
        int prev1 = nums[start], prev2 = 0;

        for(int i = start + 1; i < end; i++){
            int notPick = prev1;
            int pick = nums[i] + (i > 1 ? prev2 : 0);
            prev2 = prev1;
            prev1 = max(pick, notPick);
        }

        return prev1; 
    }

public:
    int rob(vector<int>& nums) {

        int takeFirst = Helper(nums, 0, nums.size() - 1);
        int takeLast =  1 < nums.size() ? Helper(nums, 1, nums.size()) : 0;

        return max(takeFirst, takeLast);
    }
};