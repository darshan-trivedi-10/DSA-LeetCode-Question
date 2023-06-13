class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // Sorted Array Here 
        // All the range so that all the number of array must be in the range,
        // And range must not contains any extra elements

        int size = nums.size();
        int idx = -1, startR, endR;

        vector<string> range;
        for(int i = 0; i < size; i++){
            if(idx == -1){
                idx = 0;
                startR = nums[i], endR = nums[i];
            }else{
                if(nums[i] == endR + 1){
                    endR++;
                }else{
                    string currR;
                    if(startR == endR){
                        currR = to_string(startR);
                    }else{
                        currR = to_string(startR) + "->" + to_string(endR);
                    }
                    range.push_back(currR);
                    startR = nums[i], endR = nums[i];
                }
            }
        }

        if(idx != -1){
            string currR;
            if(startR == endR){
                currR = to_string(startR);
            }else{
                currR = to_string(startR) + "->" + to_string(endR);
            }
            range.push_back(currR);
        }

        return range;
    }
};