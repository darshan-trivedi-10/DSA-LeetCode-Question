class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        
        for(int i = 0; i<magazine.size(); i++){
            int pos = magazine[i] - 'a';
            arr[pos]++;
            
        }
        
        for(int i = 0; i<ransomNote.size(); i++){
            int pos = ransomNote[i] - 'a';
            if(!arr[pos]--){
                return false;
            }
        }
        
        return true;
        
    }
};