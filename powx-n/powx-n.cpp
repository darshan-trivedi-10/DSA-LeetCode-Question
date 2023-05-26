class Solution {
public:
    double myPow(double x, long long n) {
        // Check if n is negative and update x and n accordingly
        bool is_x_negative = false;
        if (n < 0) {
            is_x_negative = true;
            n = -n;
        }
        
        // Compute the power using binary exponentiation
        double ans = 1.0;
        while (n > 0) {
            if (n & 1) {
                ans = ans * x;
            }
            x = x * x;
            n = n / 2;
        }
        
        // Return the result based on the value of is_x_negative
        return is_x_negative ? (1.0 / ans) : ans;
    }
};
