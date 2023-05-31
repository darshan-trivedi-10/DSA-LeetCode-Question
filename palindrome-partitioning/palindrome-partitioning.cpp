class Solution
{
    bool isPalindrome(string str)
    {
        int i = 0, j = str.size() - 1;
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++, j--;
        }

        return true;
    }
    void Helper(string s, vector<vector<string>> &ans, vector<string> &ds, int idx)
    {
        int n = s.size();
        if (idx == n)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            if (isPalindrome(s.substr(idx, i - idx + 1)))
            {
                ds.push_back(s.substr(idx, i - idx + 1));
                Helper(s, ans, ds, i + 1);
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<string> ds;
        vector<vector<string>> ans;
        Helper(s, ans, ds, 0);
        return ans;
    }
};