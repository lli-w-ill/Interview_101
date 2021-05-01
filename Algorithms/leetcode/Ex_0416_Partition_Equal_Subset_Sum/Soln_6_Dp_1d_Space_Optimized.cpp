#include <vector>
#include <numeric>      // std::accumulate

using std::vector;
using std::accumulate;

class Solution_6 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 特判
        if (sum % 2 != 0) {
            return false;
        }

        int targetSum = sum / 2;
        int size = nums.size();
        
        // dp[j] 表示在 nums 中数字是否能够凑成 累加和为j
        // 能凑成 j，则dp[j] = true；否则为 false
        vector<bool> dp (targetSum + 1, false);
        // 初始化 dp[0] 为 true，因为第一列相当于 nums 中数字中是否能凑成累加和为0
        // 直接什么数字都不选就可以凑成 0
        dp[0] = true;

        // 开始填表
        for (int i = 1; i <= size; i++) {   // 外层循环代表当前正在考虑的数字
            // 获得当前的数字
            int num = nums[i-1];

            // 与 01背包问题 相同，当用空间压缩时，内层循环需要从后向前循环，因为状态转移方程在更新新一行后面下标的值时，需要用到「上一行前面下标的值」
            for (int j = targetSum; j >= 1; j--) { 
                if (j - num >= 0) {
                    // 如果 当前的列下标-当前数字 是一个合法的下标，则一共有两种选择：
                    //  1. 将当前数字 (nums[i]) 划分出去    ->  dp[j-num]
                    //  2. 将当前数字 (nums[i]) 不划分出去  ->  dp[j]
                    dp[j] = dp[j-num] || dp[j];
                } else {
                    // 如果 当前的列下标-当前数字 就不是一个合法的下标，则只有一种选择，即上述的第2种选择
                    dp[j] = dp[j];
                }
            }
        }

        return dp[targetSum];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

