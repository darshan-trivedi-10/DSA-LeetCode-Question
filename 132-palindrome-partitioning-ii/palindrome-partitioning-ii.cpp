class Solution {
    bool is_palindrome(string &str, int start, int end){
        while(start < end){
            if(str[start] != str[end]){
                return false;
            }
            start++, end--;
        }

        return true;
    }

    int Helper(string &str, int index, vector<int> &dp){
        if(index == str.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int totalPalindrome = INT_MAX;
        for(int i = index; i < str.size(); i++){
            if(is_palindrome(str, index, i)){
                totalPalindrome = min(totalPalindrome, 1 + Helper(str, i + 1, dp));
            }
        }

        return dp[index] = totalPalindrome;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return Helper(s, 0, dp) - 1;   
    }
};