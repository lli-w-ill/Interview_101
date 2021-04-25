#include <cmath>

using std::sqrt;

class Solution_1 {
public:
    bool judgeSquareSum(int c) {
        // 左右指针需要用 long 型，因为 squareSum 可能会溢出
        long l = 0;
        long r = sqrt(c);

        while (l <= r) {    // 注：这里需要包括 = 号
            long squareSum = l * l + r * r;
            if (squareSum < c) {
                l ++;
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

