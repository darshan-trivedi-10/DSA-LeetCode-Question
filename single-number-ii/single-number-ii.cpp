class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();

        vector<int> bits(32, 0);
        for(int i = 0; i < size; i++){
            int ele = nums[i];
            for(int j = 0; j < 32; j++){
                if((1 << j) & nums[i]){
                    bits[j]++;
                }
            }
        }

        int singleNum = 0;
        for(int i = 0; i < 32; i++){
            if(bits[i]%3 != 0){
                singleNum = singleNum | (1 << i);
            }
        }

        return singleNum;
    }
};
/*
5 = 101
(1 >> j)

*/