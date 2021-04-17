#include <climits>  // INT_MIN

class Solution_1 {
public:
    bool isPowerOfThree(int n) {
        // 特判
        if (n == 0) {
            return false;
        }
        if (n == INT_MIN) {
            return false;
        }
        if (n < 0) {
            return false;
        }

        while (n > 1) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }

        return true;
    }
};
