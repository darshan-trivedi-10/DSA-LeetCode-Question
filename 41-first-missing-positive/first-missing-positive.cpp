class Solution
{
public:
    int firstMissingPositive(vector<int> &arr)
    {
        int i = 0, n = arr.size();
        while (i < n)
        {
            int correct = abs(arr[i]) - 1;
            if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[correct])
            {
                swap(arr[i], arr[correct]);
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != (i + 1))
            {
                return i + 1;
            }
        }

        return n+1;
    }
};