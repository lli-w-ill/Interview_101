#include <cmath>

using std::sqrt;

class Solution_2 {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        int r = sqrt(c);

        while (l <= r) {    // 注：这里需要包括 = 号
            long squareSum = l * l + r * r;
            if (squareSum < c) {
                // 右移左指针之前提前判断下次是否会溢出
                if (c - r * r >= (l + 1) * (l + 1)) {
                    // 如果右移左指针 不会导致下一次的 squareSum 溢出，才进行右移
                    l ++;
                } else {
                    // 如果右移会导致溢出，则左移右指针
                    r --;
                }
            } else if (squareSum > c) {
                r --;
            } else if (squareSum == c) {
                return true;
            }
        }

        return false;

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

