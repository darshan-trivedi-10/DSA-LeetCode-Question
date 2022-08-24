class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1){
            return true;
        }
        
        long long x = 3;
        while(x<=n){
            if(x==n){
                return true;
            }
            
            x = x*3;
        }
        
        return false;
        
    }
};

// [011] - 3
// [1001] - 9
// [11011] = 27
// [1010001] = 81

