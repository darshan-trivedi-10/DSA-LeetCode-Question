class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int size = nums.size();

        int ms = INT_MIN, cs = 0;
        for(int i = 0; i < size; i++){
            cs += nums[i];
            ms = max(ms, cs);
            if(cs < 0){
                cs = 0;
            }
        }

        return ms;
    }
};