class Solution_3 {
public:
    int trailingZeroes(int n) {
        int five = 0;   // 因子 5 的个数

        for (int i = 1; i <= n; i++) {  // 循环 n 遍
            int temp = i;

            while (temp > 0) {  // 循环 log_5 {temp} 遍
                if (temp % 5 == 0) {
                    five ++;
                    temp /= 5;
                } else {
                    break;
                }
            }
        }

        return five;
    }
};

// 参考题解（推荐）：https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/
// 思路上和 Soln_1 的思路一样，但是不需要计算 2 的因子数了，因为 2 的个数永远大于 5 的个数
