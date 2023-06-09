class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int size = nums.size();

        vector<int> ans;
        multiset<int> myMultiset;
        for (int i = 0; i < size; i++) {
            myMultiset.insert(nums[i]);
            if (myMultiset.size() == k) {
                ans.push_back(*myMultiset.rbegin());
            }
            if (i >= k - 1) {
                auto it = myMultiset.find(nums[i - k + 1]);
                myMultiset.erase(it);
            }
        }

        return ans;
    }
};
