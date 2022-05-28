class Solution
{
    bool isValid(char ch)
    {
        return (ch <= '9' and ch >= '0') || (ch >= 'a' and ch <= 'z') || (ch >= 'A' and ch <= 'Z');
    }

public:
    string reverseWords(string s)
    {
        int n = s.size();
        string ans = "", word = "";
        bool space = false;
        for (int i = n-1; i >= 0; i--)
        {
            if (isValid(s[i]))
            {
                space = true;
                word.push_back(s[i]);
            }
            else if (space)
            {
                reverse(word.begin(), word.end());
                word += " ";
                ans += word;
                word = "";
                space = false;
            }
        }
        
        if(space){
            reverse(word.begin(), word.end()); 
            ans += word;
        }
        
        if(!isValid(ans[ans.size()-1])){
            ans.pop_back();  
        }

        return ans;
    }
};