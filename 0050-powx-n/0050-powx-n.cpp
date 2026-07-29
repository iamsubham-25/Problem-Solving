class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // Use long long to avoid overflow when n = INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1.0;
        double current_product = x;

        while (N > 0) {
            if (N % 2 == 1) { // If N is odd, multiply ans by current_product
                ans *= current_product;
            }
            current_product *= current_product; // Square the base
            N /= 2; // Divide exponent by 2
        }

        return ans;
    }
};