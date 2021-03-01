#include <limits.h>

class Solution_1 {
public:
    int reverse(int x) {
        int res = 0;
        bool neg = false;
        
        if (x < 0) {
            if (x <= INT_MIN) {
                return 0;
            }
            neg = true;
            x = -x;
        }

        int MAX = (unsigned int) -1 >> 1;       // 可以直接使用 INT_MAX, INT_MIN
        int MIN = ~MAX;
        // cout << MIN << " " << MAX << endl;

        while (x > 0) {
            // cout << res << " " << x % 10 << endl;
            if (neg && -res < MIN / 10) {
                return 0;
            }
            if (!neg && res > (MAX / 10)) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }

        return neg ? -res : res;
    }
};

// C++ 计算 INT_MIN, INT_MAX: https://stackoverflow.com/questions/9402386/get-int-max-with-bit-operations
// 注：严格来说，这个解法 while 循环中的判断不准确，详见 Soln_2
