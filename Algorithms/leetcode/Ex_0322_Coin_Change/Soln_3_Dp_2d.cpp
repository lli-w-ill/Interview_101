#include <vector>

using std::vector;
using std::min;

class Solution_3 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();

        // dp[i][j] 表示只用 coins[0 ... i-1] 时，凑成金额 j 所使用的最少的硬币数
        vector<vector<int>> dp (size + 1, vector<int> (amount + 1, INT_MAX - 1));

        // 初始化第一列为 0，因为凑成金额 0，不需要任何硬币
        for (int i = 0; i <= size; i++) {
            dp[i][0] = 0;
        }

        // 开始填表 (从第一行开始)
        for (int i = 1; i <= size; i++) {   // i-1: 当前正在考虑的金币下标
            int value = coins[i-1];

            for (int j = 0; j <= amount; j++) { // j: 当前要凑的金额数
                if (j >= value) {
                    // 如果当前需要凑的金额数 >= 当前硬币的额度，那么有两种可能
                    //  1. 用当前硬币   -> dp[i][j-value] + 1
                    //  2. 不用当前硬币 -> dp[i-1][j]
                    dp[i][j] = min(dp[i][j-value] + 1, dp[i-1][j]);
                } else {
                    // 如果当前要凑的金额数 < 当前硬币的额度，那么只有一种可能，即上述的第 2 种可能
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        if (dp[size][amount] == INT_MAX - 1) {
            return -1;
        } else {
            return dp[size][amount];
        }
        
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
