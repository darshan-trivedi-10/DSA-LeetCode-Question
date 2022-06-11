class Solution {
public:
    int minOperations(vector<int>& nums, int X) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(),0)-X;
        int currSum = 0, maxLen = 0;
        int startIdx = 0;
        bool found = true;
        
        for(int i = 0; i<n; i++){
            currSum += nums[i];
            
            while(startIdx <= i and currSum > target){
                currSum -= nums[startIdx];
                startIdx++;
            }
            
            if(currSum == target){
                found = false;
                maxLen = max(maxLen, i-startIdx+1);
            }
        }
        
        maxLen = n - maxLen;
        if(found){ 
            maxLen = -1;
        }
        
        return maxLen;    
    }
};