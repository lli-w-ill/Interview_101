#include <cmath>

using std::log10;
using std::fmod;

class Solution_4 {
public:
    bool isPowerOfThree(int n) {
        // 用log换底公式计算 log_3(n)
        double log3n = log10(n) / log10(3);

        // 判断 log3n 是不是一个整数
        return fmod(log3n, 1.0) == 0;

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// fmod 方法：http://www.cplusplus.com/reference/cmath/fmod/?kw=fmod
