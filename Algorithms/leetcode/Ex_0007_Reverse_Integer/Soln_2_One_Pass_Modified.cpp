class Solution_2 {
public:
    int reverse(int x) {
        int res = 0;

        // 手动求 INT_MIN, INT_MAX
        int MAX = (unsigned int) -1 >> 1;
        int MIN = ~MAX;
        // cout << MIN << " " << MAX << endl;

        while (x != 0) {
            // cout << res << " " << x % 10 << endl;
            if (res < MIN / 10 || res == MIN / 10 && x < -8) {
                return 0;
            }
            if (res > (MAX / 10) || res == MAX / 10 && x > 7) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }
};

// C++ 计算 INT_MIN, INT_MAX: https://stackoverflow.com/questions/9402386/get-int-max-with-bit-operations
// 注意 while 循环条件的是 x != 0，因为无论 x 是正是负，x 最终都会归于 0
// 注意 while 循环条件中 if 的判断条件，仍需要考虑 x % 10 的结果
// 这道题分析详见题解（非常推荐）：https://leetcode-cn.com/problems/reverse-integer/solution/tu-jie-7-zheng-shu-fan-zhuan-by-wang_ni_ma/
