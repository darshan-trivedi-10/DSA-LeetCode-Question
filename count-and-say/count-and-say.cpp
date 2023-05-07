class Solution {
public:
    string solve(int n , string s){
        if(n == 0) return s;
           
        string temp = "";
        char prev = s[0];
        int count = 1;

        for(int i = 1; i<s.size();i++){
            if(prev == s[i]){
                count++;
            }
            else {
                temp = (temp + (char)(count + '0')) + prev;
                prev = s[i];
                count = 1;
            }
       }
       temp = (temp + (char)(count + '0')) + prev;
       
       return solve(n-1,temp);
    }

    string countAndSay(int n) {
        
      return solve( n-1 ,"1");

    }
};