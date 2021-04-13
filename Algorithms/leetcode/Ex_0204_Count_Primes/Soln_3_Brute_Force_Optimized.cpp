class Solution_3 {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }

        // 初始素数数量是 1 (素数2)
        int count = 1;
        for (int i = 3; i < n; i++) {
            // 如果 i 是 2 倍数，那么 i & (i-1) == 0（建议在纸上画出所有bits比较）
            // i & 1 等价于 i % 2
            if ((i & 1) == 0) {
                continue;
            }
            bool isPrime = true;
            // 这里上界到 √i 就结束，而且 用 j*j <= i 比用 j <= √i 更好
            for (int j = 3; j * j <= i; j+= 2) {    // 步数为 2 因为 2 的倍数一定不是质数
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                count ++;
            }
        }

        return count;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/count-primes/solution/ji-shu-zhi-shu-bao-li-fa-ji-you-hua-shai-fa-ji-you/

