#include <vector>

using std::vector;

class Solution_3 {
public:
    int climbStairs(int n) {
        // 特判
        if (n < 0) {
            return 0;
        }
        if (n == 0 || n == 1 || n == 2) {
            // n == 0: (NULL)
            // n == 1: 1
            // n == 2: 1 + 1 或 2
            return n;
        }

        // dp[i] 达到当前位置 i 有多少种方法
        vector<int> dp (n + 1, 0);
        // base case
        dp[0] = 1;
        dp[1] = 1;

        // 状态转移方程: dp[i] = dp[i-1] + dp[i-2]
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
