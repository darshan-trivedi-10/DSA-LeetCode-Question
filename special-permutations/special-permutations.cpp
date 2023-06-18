class Solution {
public:
    int n;
    const int mod = 1e9 + 7;
    int recurse(int last, int bot, vector<int>& nums, vector<vector<int>>& dp){
        if(bot == ((1<<n)-1)) return 1;
        if(dp[bot][last] != -1) return dp[bot][last];
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int num = 1ll << i;
            if((num&bot) == 0){
                if(nums[i] % nums[last] == 0 || nums[last] % nums[i] == 0){
                    int newbot = (num | bot);
                    ans = (ans + recurse(i, newbot, nums, dp)) % mod;
                }
            }
        }
        return dp[bot][last] = ans;
    }
    int specialPerm(vector<int>& nums) {
        n = nums.size();
        int ma = (1<<n) + 1;
        vector<vector<int>> dp(ma, vector<int> (n, -1));
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int num = 1ll << i;
            ans = (ans + recurse(i, num, nums, dp)) % mod;
        }
        return ans;
    }
};