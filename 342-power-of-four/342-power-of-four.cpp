class Solution {
    /*
    Basically the powers of 4 are simple numbers in binary, there is only 1 bit set and it's in the 1,3,5,7th etc position.
    So we just check that the number has a popcount of 1 and also that bit is in an odd position.
    */
public:
    bool isPowerOfFour(int n) {
        return (__builtin_popcount(n)==1 && ffs(n)%2);
    }
};