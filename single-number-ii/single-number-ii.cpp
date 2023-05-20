class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int size = nums.size();

        int ans = 0;
        for(int i = 0; i < 32; i++){
            int sum = 0;
            for(int j = 0; j < size; j++){
                if(((nums[j] >> i) & 1) == 1){
                    sum++;
                }
            }

            if(sum%3){
                ans = ans | 1 << i;
            }
        }

        return ans;


    }
};