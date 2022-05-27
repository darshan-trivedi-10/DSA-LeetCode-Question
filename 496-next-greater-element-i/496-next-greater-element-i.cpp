class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mpp;
        vector<int> ans;
        stack<int> st;
        for (int i = n2 - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                mpp.insert({nums2[i], -1});
                st.push(nums2[i]);
            }
            else
            {
                int topEle = st.top();
                while (!st.empty() and st.top() <= nums2[i])
                {
                    st.pop();
                    if (!st.empty())
                        topEle = st.top();
                }
                if (st.empty())
                {
                    mpp.insert({nums2[i], -1});
                    st.push(nums2[i]);
                }
                else
                {
                    mpp.insert({nums2[i], topEle});
                    st.push(nums2[i]);
                }
            }
        }

        for (int i = 0; i < n1; i++)
        {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};