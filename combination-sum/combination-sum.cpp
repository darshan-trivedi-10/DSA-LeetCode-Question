class Solution {
    void generate(vector<int> &c, vector<int> &ds, vector<vector<int>> &result, int idx, int target){

        if(idx == c.size()){
            if(target == 0){
                result.push_back(ds);
            }
            return;
        }

        if(c[idx] <= target){
            ds.push_back(c[idx]);
            generate(c, ds, result, idx, target - c[idx]);
            ds.pop_back();
        }

        generate(c, ds, result, idx + 1, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        generate(c, ds, result, 0, target);
        return result;
    }
};