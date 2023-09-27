class Solution {
    
    bool compare(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;
    
        int first = 0;
        int second = 0;
    
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false; 
    }

    int Helper(vector<string> &words, int index, int prevIndex, vector<vector<int>> &dp){
        if(index == words.size()){
            return 0;
        }

        if(dp[index][prevIndex + 1] != -1){
            return dp[index][prevIndex + 1];
        }

        int len = Helper(words, index + 1, prevIndex, dp);
        if(prevIndex == -1 || compare(words[index], words[prevIndex])){
            len = max(len, 1 + Helper(words, index + 1, index, dp));
        }

        return dp[index][prevIndex + 1] = len;
    }


public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return Helper(words, 0, -1, dp);
    }
};