#include <cmath>

using std::log;
using std::abs;

class Err_1 {
public:
    bool isPowerOfThree(int n) {
        // 特判
        if (n == 0) {
            return false;
        }
        if (n < 0) {
            return false;
        }

        // 这里不可以用 == 0，因为浮点数之差会有误差
        return abs((log(n) / log(3)) - ceil(log(n) / log(3))) < 1e-6;
    }
};

// 思路：
// 如果存在整数 x，使得 3 ^ x == n，那么两边同时取 log3，得 log3(3^x) = log3(n)
// x = log3(n)，所以只需要检查 log3(n) 是不是整数即可，但是c++中没有log3函数，所以需要用到换底公式 log3(n) = loga(n) / loga(3)
// 该方法存在的问题：
// 当 n 非常非常接近 3 的幂时，可能c++算出的 log3(n) 也是整数
// 例子：1594322 其实不是 3 的幂，但是 3^13 = 1594323，只差了1，但是 log(n) / log(3) 的确返回的是整数
// 所以这个解法有些问题
