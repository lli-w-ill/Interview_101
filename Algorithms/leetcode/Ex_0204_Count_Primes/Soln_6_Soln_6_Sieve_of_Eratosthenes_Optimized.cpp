#include <vector>
#include <cmath>

using std::vector;
using std::sqrt;

class Solution_6 {
public:
    int countPrimes(int n) {
        // 特判
        if (n <= 2) {
            return 0;
        }

        int count = n / 2;  // 除去 1~n-1 之间的所有偶数（因为都是 2 的倍数）
        vector<bool> isPrime(n, true);
        // 注：这里不用先遍历一遍 1~n-1 将所有 2 的倍数数字的下标都置为 false，是因为在接下来的循环中 i 每次递增 2，所以永远不会置为偶数
        // 所以 isPrime 中对应的偶数下标其实是没有用的

        int i = 3;  // 从 3 开始遍历
        int sqrtn = sqrt(n);

        while (i <= sqrtn) {    // 优化点一：最小因子一定小于等于 n 的开方
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    if (isPrime[j]) {
                        isPrime[j] = false;
                        --count;
                    }
                }
            }
            
            // 递增 i 到下一个「还为被筛选的奇数」
            do {
                i += 2;
            } while (i <= sqrtn && isPrime[i] == false);

        }

        return count;

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

