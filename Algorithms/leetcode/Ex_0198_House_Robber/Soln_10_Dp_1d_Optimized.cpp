#include <vector>

using std::vector;
using std::max;

class Solution_10 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        
        // base case
        int pre2 = 0;          // 到第 i-2 个房子时（不包括第 i-2 个房子），能偷到最多的钱
        int pre1 = nums[0];    // 到第 1-1 个房子时（不包括第 i-1 个房子），能偷到最多的钱

        // 需要加上特判
        if (size == 1) {
            return pre1;
        }

        int cur;

        // 状态转移方程: dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
        for (int i = 2; i <= size; i++) {
            // pre1: 不偷当前第 i 个房子能得到的最多的钱
            // pre2 + nums[i-1]: 偷当前第 i 个房子能得到的最多的钱
            cur = max(pre1, pre2 + nums[i-1]);

            pre2 = pre1;
            pre1 = cur;
        }

        return cur;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
