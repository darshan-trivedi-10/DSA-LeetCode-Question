class Solution {

    bool isValid(char a, char b){
        if(a == '1'){
            return true;
        }
        if(a == '2'){
            return b <= '6';
        }

        return false;
    }

    int Helper(string &s, int index, vector<int> &dp){
        if(index >= s.size()){
            return 1;
        }

        if(s[index] == '0'){
            return 0;
        }

        if(index == s.size() - 1){
            return 1;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int one = 0, two = 0;
        one = Helper(s, index + 1, dp);
        if(index != s.size() -1 && isValid(s[index], s[index + 1])){
            two = Helper(s, index + 2, dp);
        }
        return dp[index] = one + two;
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return Helper(s, 0, dp);
    }
};