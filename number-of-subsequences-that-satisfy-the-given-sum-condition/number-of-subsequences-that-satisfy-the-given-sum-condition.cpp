

class Solution {

    static int multiply(int n){
        int start = 1, mod = 1000000007;
        for(int i = 1; i <= n; i++){
            start = (start * 2)%mod;
        }

        return (start%mod);
    }


public:
    int numSubseq(vector<int>& nums, int target) {
        const int n = nums.size(), mod = 1000000007;

        vector<int> mul(n + 1, 1);
        for(int i = 1; i <=n; i++){
            mul[i] = (2 * mul[i - 1])%mod;
        }


        sort(nums.begin(), nums.end());
        int l = 0, r = n-1, ans = 0;
        while(l <= r){
            if(nums[l] + nums[r] > target){
                r--;
            }else{
                if(r == l){
                    ans++;
                }else{
                    ans = (ans + mul[r - l]) % mod;
                }
                l++;
            }
        }

        return ans;
    }
};