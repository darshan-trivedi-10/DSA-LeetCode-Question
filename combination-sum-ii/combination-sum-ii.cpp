class Solution {

    void generate(vector<int> &c, vector<int> &ds, vector<vector<int>> &result, int idx, int target){
        if(target == 0){
            result.push_back(ds);
            return;
        }

        for(int i = idx; i < c.size(); i++){
            if(i > idx && c[i] == c[i-1]){
                continue;
            }

            if(c[i] > target){
                break;
            }
            
            ds.push_back(c[i]);
            generate(c, ds, result, i + 1, target - c[i]);
            ds.pop_back();
        }

    }
    

public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(c.begin(), c.end());
        generate(c, ds, result, 0, target);
        return result;
    }
};