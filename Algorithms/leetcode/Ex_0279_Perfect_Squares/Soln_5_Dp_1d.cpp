#include <vector>

using std::vector;
using std::min;

class Solution_5 {
public:
    int numSquares(int n) {
        // dp[i] 表示数字 i 需要的最少数量的完全平方数
        vector<int> dp (n + 1, INT_MAX);

        // base case
        dp[0] = 0;  // 数字 0 不需要任何完全平方数

        // 开始填数组
        for (int i = 1; i <= n; i++) {
            // 状态转移方程：dp[i] = min(dp[i], dp[i-1^2] + 1, dp[i-2^2] + 1, ... dp[i-floor(sqrt(i))^2] + 1)
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

