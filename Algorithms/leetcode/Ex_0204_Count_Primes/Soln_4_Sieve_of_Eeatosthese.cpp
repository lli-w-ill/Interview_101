#include <vector>

using std::vector;

class Solution_4 {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> isPrime(n, true);
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count ++;
                // 将 i 的所有倍数都设为「非质数」
                for (int j = i + i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return count;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/count-primes/solution/ji-shu-zhi-shu-bao-li-fa-ji-you-hua-shai-fa-ji-you/

