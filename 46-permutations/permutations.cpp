class Solution {

    void generate(vector<int> &nums, vector<vector<int>> &premutations, int idx){
        if(idx == nums.size()){
            premutations.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            generate(nums, premutations, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> premutations;
        generate(nums, premutations, 0);

        return premutations;
    }
};