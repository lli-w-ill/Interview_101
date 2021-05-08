#include <vector>

using std::vector;

class Solution_1 {
public:
    int minSteps(int n) {
        // dp[i] 表示延展到 i个'A'字符时的最少操作次数
        vector<int> dp (n + 1, 0);

        // 内层循环最多循环到 h
        int h = sqrt(n);

        for (int i = 2; i <= n; i++) {      // i: 当前要求『长度为 i 的 'A' 需要操作的最小次数』
            // 最坏情况：通过 paste 操作粘贴 i 次长度为 1 的 'A' 得到长度为 i 的字符串
            dp[i] = i;
            
            for (int j = 2; j <= h; j++) {  // j: 考虑是否可以通过粘贴长度为 j 的 'A' 的到长度为 i 的字符串
                if (i % j == 0) {
                    // 可以通过粘贴 i/j 次长度为 j 的 'A' 来得到长度为 i 的 'A'
                    // 状态转移方程：得到长度为 j 的 'A' 的最少操作次数 + i/j 次粘贴长度为 j 的操作次数
                    // dp[i] = min(dp[i], dp[j] + i / j);   // 错误的
                    dp[i] = dp[j] + dp[i/j];
                }
            }
        }

        return dp[n];

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
