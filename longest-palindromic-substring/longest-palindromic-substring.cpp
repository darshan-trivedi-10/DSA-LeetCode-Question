class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();

        int left = 0, right = 0, maxLen = 0;
        for(int i = 1; i < n; i++){
            int l = i-1, r = i;
            while((l>=0 && r<n) && s[l]==s[r]){
                int len = r-l+1;
                if(len>maxLen){
                    right = r, left = l;
                    maxLen = len;
                }
                l--,r++;
            }

            l = i-1, r = i+1;
            while((l>=0 && r<n) && s[l]==s[r]){
                int len = r-l+1;
                if(len>maxLen){
                    right = r, left = l;
                    maxLen = len;
                }
                l--,r++;
            }

        }

        string ans = "";
        for(int i = left; i<=right; i++){
            ans.push_back(s[i]);
        }

        return ans;
    }
};