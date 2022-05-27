class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else if (!st.empty())
            {
                int ob = st.top();
                if ((ob == '(' and ch == ')') || (ob == '[' and ch == ']') || (ob == '{' and ch == '}'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};