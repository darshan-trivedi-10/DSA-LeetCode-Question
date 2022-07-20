class Solution
{
    int isSubsequences(string &str1, string &str2)
    {
        int n = str1.size(), m = str2.size();
        int i = 0, j = 0;

        while (i < n and j < m)
        {
            if (str1[i] == str2[j])
            {
                i++, j++;
            }
            else
            {
                i++;
            }
        }

        return j == m;
    }

public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        map<string, bool> mpp;
        int ans = 0;

        for (auto x : words)
        {

            if (mpp.find(x) != mpp.end())
            {
                ans += (mpp[x] ? 1 : 0);
                continue;
            }
            
            mpp[x] = isSubsequences(s,x);
            ans += (mpp[x] ? 1 : 0);
        }

        return ans;
    }
};
