class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string org = a;
        while(a.length()<b.length()){
            a+=org;
        }
        if(a.find(b)!=string::npos)return a.length()/org.length();
        a+=org;
        if(a.find(b)!=string::npos)return a.length()/org.length();
        return -1;    
        
    }
};