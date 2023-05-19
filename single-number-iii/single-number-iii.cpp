class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        const int size = nums.size();

        long long xorr = 0;
        int x = 0, y = 0;
        for(int i = 0; i < size; i++){
            xorr = xorr ^ nums[i];
        }
        
        int setBitNo = xorr & -xorr;
        
        for (int i = 0; i < size; i++) {
            if ((nums[i] & setBitNo) == 0) {
                x = x ^ nums[i];
            }else {
                y = y ^ nums[i];
            }
        }

        return {x,y};
    }
};