#include <vector>

using std::vector;

class Solution_5 {
public:
    int countPrimes(int n) {
        // 特判
        if (n <= 2) {
            return 0;
        }

        int count = n - 2;  // 1~n-1 除去 1
        vector<bool> isPrime(n, true);
        isPrime[0] = false; // 1 不是质数

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                // 说明 i 没有被之前的数字筛出去

                // 筛选小于 n 的所有 i 的倍数
                for (int j = 2 * i; j < n; j += i) {
                    if (isPrime[j]) {
                        isPrime[j] = false;
                        count --;
                    }
                }
            }
        }

        return count;
        
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
