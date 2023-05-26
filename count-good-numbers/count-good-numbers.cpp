class Solution {
    long long powFunction(long long x, long long n){
        if(n == 0){
            return 1;
        }
        long long ans = powFunction(x, n/2);
        ans *= ans;
        ans %= 1000000007;
        if(n%2==1){
            ans *= x;
            ans %= 1000000007;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;
        return (powFunction(5, even) * powFunction(4, odd))%1000000007;
    }
};