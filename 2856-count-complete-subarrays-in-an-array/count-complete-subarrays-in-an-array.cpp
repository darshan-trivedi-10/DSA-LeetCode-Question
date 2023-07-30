class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int size = nums.size();
        
        set<int> s(nums.begin(), nums.end());
        int uniqueElement = s.size();

        unordered_map<int,int> mpp;

        int left = 0, count = 0;
        for(int right = 0; right < size; right++){
            mpp[nums[right]]++;

            while(mpp.size() == uniqueElement){
                count += (size - right);
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
        }

        return count;
    }
};