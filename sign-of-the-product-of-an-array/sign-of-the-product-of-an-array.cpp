class Solution {
public:
    int arraySign(vector<int>& nums) {
        int minus = 0, plus = 0, zero = 0;

        for(const int &num : nums){
            if(num==0){
                zero++;
                break;
            }else if(num > 0){
                plus++;
            }else{
                minus++;
            }
        }

        if(zero > 0){
            return 0;
        }

        if(minus > 0 && minus%2 != 0){
            return -1;
        }

        return 1;

    }
};