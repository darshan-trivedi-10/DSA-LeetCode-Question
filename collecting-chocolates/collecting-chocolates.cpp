class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<int> checked(nums.size(), INT_MAX);

        vector<int> cnum(nums.begin(), nums.end());
        for(auto ele : nums){
            cnum.push_back(ele);
        }

        long long ans = LONG_MAX;
        for(int i = 0; i < nums.size(); i++){
            long long sum = 0;
            for(int j = 0; j < nums.size(); j++){
                if(checked[j] > cnum[i + j]){
                    checked[j] = cnum[i + j];
                }
                sum += checked[j];
            }
            sum += i * 1LL * x;
            ans = min(ans, sum);
        }

        return ans;
    }
};