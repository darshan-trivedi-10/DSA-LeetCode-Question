class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int size = nums.size();
        int left = 0, right = 0;

        int sum = 0, minLen = INT_MAX;
        while(right < size){
            if(sum < target){
                sum += nums[right];
                right++;
            }
            while(sum >= target){
                minLen = min(minLen, right - left);
                sum -= nums[left];
                left++;
            }
        }

        // 2 3 1 2 4 3
        //       6 6 9
        // 

        return minLen == INT_MAX ? 0 : minLen;
    }
};