class Solution {

    int devide(int start, int end, int k, string &str){

        if(start >= end){
            return 0;
        }

        map<char,int> freq;
        for(int i = start; i < end; i++){
            freq[str[i]]++;
        }

        int last = start, ans = 0;
        for(int i = start; i < end; i++){
            if(freq[str[i]] < k){
                ans = max(devide(last, i, k, str),ans);
                last = i + 1;
            }
        }

        if(last != start && last != end){
            ans = max(devide(last, end, k, str),ans);
        }

        // aab, k = 2
        if(last == start){
            return end - start;
        }

        return ans;
    }

public:
    int longestSubstring(string s, int k) {
        const int size = s.size();
        return devide(0, size, k, s);
    
    }
};