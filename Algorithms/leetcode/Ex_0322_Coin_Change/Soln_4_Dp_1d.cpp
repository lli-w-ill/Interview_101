#include <vector>

using std::vector;
using std::min;

class Solution_4 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        if (size == 0) {
            return -1;
        }

        // dp[j] 表示凑成金额 j 所使用的最少的硬币数
        vector<int> dp (amount + 1, INT_MAX - 1);

        // 初始化第一列为 0，因为凑成金额 0，不需要任何硬币
        dp[0] = 0;

        // 开始填表 (从第一行开始)
        for (int j = 1; j <= amount; j++) { // j: 当前要凑的金额数
            for (const int &coin : coins) {
                if (j >= coin) {
                    // 如果当前需要凑的金额数 >= 当前硬币的额度，那么有两种可能
                    //  1. 用当前硬币   -> dp[j-coin] + 1
                    //  2. 不用当前硬币 -> dp[j]
                    dp[j] = min(dp[j-coin] + 1, dp[j]);
                }
            }
        }

        if (dp[amount] == INT_MAX - 1) {
            return -1;
        } else {
            return dp[amount];
        }
        
    }
};

// 参考题解：https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
