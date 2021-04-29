class Solution_4 {
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

        // base case
        int pre2 = 1;   // 走到 i-2 的方法数
        int pre1 = 1;   // 走到 i-1 的方法数
        int cur;

        // 状态转移方程: dp[i] = dp[i-1] + dp[i-2]
        for (int i = 2; i <= n; i++) {
            cur = pre2 + pre1;  // 走到 i 的方法数
            
            pre2 = pre1;
            pre1 = cur;
        }

        return cur;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
