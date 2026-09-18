class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lo = 1, hi = num;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            } else if (square < num) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return false;
    }
};