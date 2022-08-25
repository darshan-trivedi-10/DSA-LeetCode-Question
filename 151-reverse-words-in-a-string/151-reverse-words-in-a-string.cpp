class Solution {
    
    bool isValid(char ch){
        return (ch>='a' and ch<='z') || (ch>='A' and ch<='Z') || (ch>='0' and ch<='9');
    }
    
    string myReverse(string &str, int s, int e){
        
        string temp = "";
        while(s<=e){
            temp.push_back(str[s]);
            s++;
        }
        
        reverse(temp.begin(), temp.end());
        return temp;
    }
    
    
public:
    string reverseWords(string str) {
        int n = str.size();
        int i = 0, j = 0;
        
        string ans = "";
        while(i<n and j<=n){

            if(!isValid(str[j]) and i==j){
                i++,j++;
            }else if(!isValid(str[j])){
                if(ans.size()>0){
                    ans = ans + " ";
                }
                ans = ans + myReverse(str, i,j-1);
                i = j+1;
                j = j+1;
            }else{
                j++;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;

    }
};