class Solution {

    int Helper(vector<int> &nums, int left, int right){
        if(left == right){
            return nums[left];
        }

        int leftScore = nums[left] - Helper(nums, left + 1, right);
        int rightScore = nums[right] - Helper(nums, left, right - 1);

        return max(leftScore, rightScore);
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp (size, vector<int>(size, -1));
        return Helper(nums, 0, nums.size() - 1) >= 0;
    }
};















