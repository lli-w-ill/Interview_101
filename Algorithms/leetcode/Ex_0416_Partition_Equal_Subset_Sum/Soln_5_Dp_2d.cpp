#include <vector>
#include <numeric>      // std::accumulate

using std::vector;
using std::accumulate;

class Solution_5 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 特判
        if (sum % 2 != 0) {
            return false;
        }

        int targetSum = sum / 2;
        int size = nums.size();
        
        // dp[i][j] 表示在 nums 中前 i-1 个数字中选数，是否能够凑成 累加和为j
        // 能凑成 j，则dp[i][j] = true；否则为 false
        vector<vector<bool>> dp (size + 1, vector<bool> (targetSum + 1, false));
        // 初始化第一列为 true，因为第一列相当于 从前 i-1 个数字中选数，是否能凑成累加和为0
        // 直接什么数字都不选就可以凑成 0
        for (int i = 0; i <= size; i++) {
            dp[i][0] = true;
        }

        // 开始填表
        for (int i = 1; i <= size; i++) {   // 外层循环代表当前正在考虑的数字
            // 获得当前的数字
            int num = nums[i-1];

            for (int j = 1; j <= targetSum; j++) {  // 内层循环从 1 开始循环（第 0 列已经全部置为 true 了
                if (j - num >= 0) {
                    // 如果 当前的列下标-当前数字 是一个合法的下标，则一共有两种选择：
                    //  1. 将当前数字 (nums[i]) 划分出去    ->  dp[i-1][j-num]
                    //  2. 将当前数字 (nums[i]) 不划分出去  ->  dp[i-1][j]
                    dp[i][j] = dp[i-1][j-num] || dp[i-1][j];
                } else {
                    // 如果 当前的列下标-当前数字 就不是一个合法的下标，则只有一种选择，即上述的第2种选择
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[size][targetSum];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
