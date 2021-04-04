#include <climits>
#include <cstdlib>  // labs

using std::labs;

class Solution_1 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }

        // 检查越界
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }
            if (divisor == 1) {
                return INT_MIN;
            }
        }

        // 检查负号，并将除数，被除数转为正数
        int sign = ((divisor < 0) ^ (dividend < 0)) ? -1 : 1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);

        int res = 0;
        while (dvd >= dvs) {
            long temp = dvs;
            int m = 1;
            while (dvd >= temp << 1) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            res += m;
        }
        
        return sign * res;
    }
};

// 参考题解：https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations
