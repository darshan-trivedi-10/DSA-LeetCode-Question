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
    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        Trie t;
        for (int i = 0; i < n; i++)
        {
            t.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, t.getMax(nums[i]));
        }

        return ans;
    }
};
