class Solution {

    double binary_exponentiation(double x, unsigned int n){
        double res = 1.00;
        while(n > 0){
            if(n&1){
                res = res * x;
            }
            x = x * x;
            n /= 2;
        }

        return res;
    }


public:
    double myPow(double x, int n) {
        bool isNegetive = n < 0 ? true : false;
        unsigned int num = abs((n * 1LL) - 0);

        double ans = binary_exponentiation(x, num);

        return (isNegetive ? 1.00/ans : ans);
    }
};