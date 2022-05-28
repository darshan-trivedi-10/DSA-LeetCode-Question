
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> leftSmaller(n), rightSmaller(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and heights[i] <= heights[st.top()])
            {
                st.pop();
            }

            if (st.empty())
            {
                leftSmaller[i] = 0;
            }
            else
            {
                leftSmaller[i] = st.top() + 1;
            }

            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and heights[i] <= heights[st.top()])
            {
                st.pop();
            }

            if (st.empty())
            {
                rightSmaller[i] = n - 1;
            }
            else
            {
                rightSmaller[i] = st.top() - 1;
            }

            st.push(i);
        }

        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            maxA = max(maxA, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));
        }

        return maxA;
    }
};