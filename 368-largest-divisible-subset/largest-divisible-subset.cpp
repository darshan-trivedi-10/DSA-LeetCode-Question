class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), hash(n, 1);

        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int prevIndex = 0; prevIndex < i; prevIndex++){
                if(
                    nums[i]%nums[prevIndex] == 0 &&
                    1 + dp[prevIndex] > dp[i]
                ){
                    dp[i] = 1 + dp[prevIndex];
                    hash[i] = prevIndex;
                }
            }
        }

        int ans = -1, lastIndex = -1;
        for(int i = 0; i < n; i++){
            if(ans < dp[i]){
                ans = dp[i];
                lastIndex = i;
            }
        }

        vector<int> subset;
        subset.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            cout<<lastIndex<<endl;
            lastIndex = hash[lastIndex];
            subset.push_back(nums[lastIndex]);
        }

        reverse(subset.begin(), subset.end());

        return subset;
    }
};

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         vector<int> dp(n, 1);
//         vector<int> hash(n, 1); // it's used for the printing the largest subsequence

//         for(int i = 0; i < n; i++){
//             hash[i] = i;
//             // going to all it's previous element and finding the maximum subsequence size
//             for(int prev_index = 0; prev_index <= i-1; prev_index++){
//                 if(
//                     nums[i]%nums[prev_index] == 0 && // this is for division
//                     1 + dp[prev_index] > dp[i] // this is for maximum finding
//                 ){
//                     dp[i] = 1 + dp[prev_index];
//                     hash[i] = prev_index;
//                 }
//             }
//         }

//         int ans = -1;
//         int lastIndex = -1;

//         // finding the maximum answer
//         for(int i = 0; i <= n-1; i++){
//             if(dp[i] > ans){
//                 ans = dp[i];
//                 lastIndex = i;
//             }
//         }

//         // getting maximum answer.
//         vector<int> subset;
//         subset.push_back(nums[lastIndex]);
//         while(hash[lastIndex] != lastIndex){
//             lastIndex = hash[lastIndex];
//             subset.push_back(nums[lastIndex]);
//         }

//         reverse(subset.begin(), subset.end());
//         return subset;
//     }
// };