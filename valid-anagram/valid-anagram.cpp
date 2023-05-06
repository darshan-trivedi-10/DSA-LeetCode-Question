class Solution {
public:
    bool isAnagram(string s, string t) {
        int ns = s.length(), nt = t.length();
        if(ns != nt) return false;
        unordered_map<char,int> mp;
        for(int i = 0;i<ns;i++) mp[s[i]]++;
        
        for(int i = 0;i<nt;i++){
            if(mp.find(t[i]) == mp.end() || mp[t[i]] <= 0) return false;
            else mp[t[i]]--;
        }
        return true;
    }
};