class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int size = nums.size();

        vector<int> duplicates;
        for(int i = 0; i < size; i++){
            int ele = abs(nums[i]) - 1;
            if(nums[ele] < 0){
                duplicates.push_back(ele + 1);
            }
            nums[ele] *= -1;
        }     

        return duplicates;
    }
};