class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        
        stack<char> st;
        for(int i = 0; i < size; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                char ch = st.top();
                if(!((ch == '(' && s[i] == ')') || (ch == '{' && s[i] == '}') || (ch == '[' && s[i] == ']'))){
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};