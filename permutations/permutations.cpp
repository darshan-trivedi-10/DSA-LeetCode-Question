class Solution {

    void generate(vector<int> &nums, vector<int> &ds, vector<bool> &visited, vector<vector<int>> &premutations){
        if(ds.size() == nums.size()){
            premutations.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                ds.push_back(nums[i]);
                visited[i] = true;
                generate(nums, ds, visited, premutations);
                ds.pop_back();
                visited[i] = false;
            }
        }

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(nums.size(), false);
        vector<int> ds;
        vector<vector<int>> premutations;
        generate(nums, ds, visited, premutations);

        return premutations;
    }
};