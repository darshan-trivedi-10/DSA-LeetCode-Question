class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int size = nums.size();

        int ans = 0, count = 0, last = -1;
        for(int i = 0; i < size; i++){
            if(nums[i] == 1){
                if(last == -1){
                    last = i;
                    count = 1;
                }else{
                    count++;
                }
            }else{
                count = 0;
            }
            
            ans = max(ans, count);
        }
        
        return ans;
        


    }
};