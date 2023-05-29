class Solution {
    void generate(vector<int> &nums, vector<int> &subset, vector<vector<int>> &ds, int idx) {
        ds.push_back(subset);
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }

            subset.push_back(nums[i]);
            generate(nums, subset, ds, i + 1);
            subset.pop_back();
        }

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ds;
        vector<int> subset;
        generate(nums, subset, ds, 0);
        return ds;
    }
};