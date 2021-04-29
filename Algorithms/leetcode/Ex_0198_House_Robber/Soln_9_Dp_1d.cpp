#include <vector>

using std::vector;
using std::max;

class Solution_9 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        // dp[i] 记录：到 i 房子时（不包括第 i 个）不触发警报下能偷到的最多的钱
        vector<int> dp (size + 1, 0);
        // base case
        dp[0] = 0;          // 到第 0 个房子时（不包括第 0 个），之前没有房子可以偷
        dp[1] = nums[0];    // 到第 1 个房子时（不包括第 1 个），之前最多只能偷第 0 个房子

        // 状态转移方程: dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
        // dp[i-1]: 不偷当前第 i 个房子
        // dp[i-2] + nums[i-1]: 偷当前第 i 个房子
        for (int i = 2; i <= size; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }

        return dp[size];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

