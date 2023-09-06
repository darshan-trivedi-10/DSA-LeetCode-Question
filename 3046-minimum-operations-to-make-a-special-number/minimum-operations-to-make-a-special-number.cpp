class Solution {

public:
    int minimumOperations(string num) {
        // 00. 25. 50, 75
        bool fiveFound = false;
        bool zeroFound = false;

        for(int i = num.size() - 1; i >= 0; i--){
            if(zeroFound && num[i] == '0'){
                return num.size() - 2 - i;
            }
            if(zeroFound && num[i] == '5'){
                return num.size() - 2 - i;
            }
            if(fiveFound && num[i] == '2'){
                return num.size() - 2 - i;
            }
            if(fiveFound && num[i] == '7'){
                return num.size() - 2 - i;
            }
            if(num[i] == '5'){
                fiveFound = true;
            }
            if(num[i] == '0'){
                zeroFound = true;
            }
        }

        if(zeroFound){
            return num.size() - 1;
        }

        return num.size();
    }
};