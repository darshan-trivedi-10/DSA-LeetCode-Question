class Solution
{
public:
    string countAndSay(int n)
    {
        unordered_map<int, char> mpp = {{1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}};
        string ans = "1";
        for (int i = 2; i <= n; i++)
        {
            string temp = "";
            for (int j = 0; j < ans.size(); j++)
            {
                int k = j, count = 1;
                while (k < ans.size() - 1 and ans[k] == ans[k + 1])
                {
                    k++;
                    count++;
                }
                temp.push_back((count+'0'));
                temp.push_back(ans[j]);
                j = k;
            }
            ans = temp;
        }

        return ans;
    }
};