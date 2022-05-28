class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(),0);
        int Sum = (n*(n+1))/2;
        
        return (Sum-totalSum);
    }
};