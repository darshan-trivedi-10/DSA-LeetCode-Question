struct Node
{
    Node *links[2];
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!temp->containsKey(bit))
            {
                temp->put(bit, new Node());
            }

            temp = temp->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *temp = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (temp->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                temp = temp->get(1 - bit);
            }
            else
            {
                temp = temp->get(bit);
            }
        }

        return maxNum;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m);
        vector<pair<int, pair<int, int>>> offlineQueries;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < m; i++)
        {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());

        Trie t;
        int i = 0;
        for (auto &it : offlineQueries)
        {
            while (i < n and nums[i] <= it.first)
            {
                t.insert(nums[i]);
                i++;
            }
            if (i != 0)
            {
                ans[it.second.second] = t.getMax(it.second.first);
            }
            else
            {
                ans[it.second.second] = -1;
            }
        }

        return ans;
    }
};