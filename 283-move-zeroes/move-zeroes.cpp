class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int size = nums.size();
        int i = 0, j = 0;
        while(i < size && j < size){
            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                j++, i++;
            }else{
                j++;
            }
        }
    }
};