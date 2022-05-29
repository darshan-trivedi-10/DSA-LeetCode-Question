class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        
        vector<int> arr(26, 0);        
        
        for(int i = 0; i<s.size(); i++){
            arr[(int)(s[i]-'a')]++;
            arr[(int)(t[i]-'a')]--;
        }
        
        for(auto it : arr){
            if(it != 0){
                return false;
            }
        }
        
        return true;
    }
};