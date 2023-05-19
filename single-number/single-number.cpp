class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int size = nums.size();

        int singleNum = 0;
        for(int i = 0; i < size; i++){
            singleNum = singleNum ^ nums[i];
        }

        return singleNum;
    }
};