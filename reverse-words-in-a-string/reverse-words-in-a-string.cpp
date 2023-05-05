class Solution {
public:
    string reverseWords(string s) {
        const int n = s.size();

        string ans = "", temp = "";
        char spaceman = ' ';
        
        for(int i = n-1; i>=0; i--){
            if(s[i] == spaceman && temp != ""){
                reverse(temp.begin(), temp.end());
                if(ans==""){
                    ans += temp;
                }else{
                    ans += spaceman + temp;
                }
                temp = "";
            }else if(s[i] != spaceman){
                temp.push_back(s[i]);
            }
        }


        if(temp != ""){
            reverse(temp.begin(), temp.end());
            if(ans==""){
                ans += temp;
            }else{
                ans += spaceman + temp;
            }        
        }

        return ans;
    }
};