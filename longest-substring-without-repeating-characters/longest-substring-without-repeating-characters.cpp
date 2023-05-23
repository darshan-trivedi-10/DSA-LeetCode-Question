class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int size = s.size();
        unordered_map<char, int> mpp;

        int last = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(mpp.find(ch) != mpp.end()){
                if(mpp[ch] >= last){
                    last = mpp[ch] + 1;
                }
            }
            mpp[ch] = i;
            ans = max(ans, i - last + 1);
        }

        // d->0, v->1, 
        // last = 0
        // ans = 2


        return ans;
    }
};

// "dvdf"