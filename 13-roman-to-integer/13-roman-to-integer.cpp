
class Solution
{
    bool isValid(char a, char b)
    {
        if (a == 'I' and (b == 'V' || b == 'X'))
        {
            return true;
        }
        if (a == 'X' and (b == 'L' || b == 'C'))
        {
            return true;
        }
        if (a == 'C' and (b == 'D' || b == 'M'))
        {
            return true;
        }

        return false;
    }

public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mpp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')
            {
                if (i != n - 1)
                {
                    if (isValid(s[i], s[i + 1]))
                    {
                        ans += -mpp[s[i]];
                    }else{
                        ans += mpp[s[i]];
                    }
                }
                else
                {
                    ans += mpp[s[i]];
                }
            }
            else
            {
                ans += mpp[s[i]];
            }
        }

        return ans;
    }
};