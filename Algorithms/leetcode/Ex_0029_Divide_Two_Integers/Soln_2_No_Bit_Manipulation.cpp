#include <climits>

class Solution_2 {
public:
    int divide(int dividend, int divisor) {
        // 检查边缘情况
        if (dividend == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            if (dividend > INT_MIN) {
                return -dividend;
            } else {
                return INT_MAX;
            }
        }

        // 标记正负号
        long dvd = dividend;
        long dvs = divisor;
        int sign;
        if ((dvd > 0 && dvs < 0) || (dvd < 0 && dvs > 0)) {
            sign = -1;
        } else {
            sign = 1;
        }

        // 转正
        dvd = dvd > 0 ? dvd : -dvd;
        dvs = dvs > 0 ? dvs : -dvs;

        int res = div(dvd, dvs);
        return res * sign;
    }

    int div(long dvd, long dvs) {
        // base case
        if (dvd < dvs) {
            return 0;
        }

        int quotient = 1;   // 商
        long temp_dvs = dvs;
        while ((temp_dvs + temp_dvs) <= dvd) {  // while 条件一定是加倍后的temp_dvs与dvd比较
            temp_dvs = temp_dvs + temp_dvs; // 除数（分母）加倍
            quotient = quotient + quotient; // 商加倍
        }

        return quotient + div(dvd - temp_dvs, dvs);
    }
};

// 参考题解：https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
