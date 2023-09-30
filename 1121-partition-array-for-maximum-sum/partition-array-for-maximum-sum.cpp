#include <bits/stdc++.h>

class Solution {

    int Helper(vector<int> &arr, int k, int index, vector<int> &dp){
        if(index == arr.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int maxSum = 0;
        int maxE = 0, size = arr.size();
        int n = min(index + k, size);
        for(int i = index; i < n; i++){
            maxE = max(maxE,arr[i]);
            int currSum = ((i - index + 1) * maxE) + Helper(arr, k, i + 1, dp);
            maxSum = max(maxSum, currSum); 
        }
        return dp[index] = maxSum;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return Helper(arr, k, 0, dp);
    }
};