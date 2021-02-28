package Algorithms.leetcode.Ex_0312_Burst_Balloons;

class Solution_3 {
    public int maxCoins(int[] nums) {
        int maxCoins = 0;
        if (nums == null) {
            return maxCoins;
        }

        // 因为要保证 nums[0] 和 nums[len-1] 被计算到，所以两头加两个虚拟边界
        int len = nums.length;
        int[] newNums = new int[len + 2];
        System.arraycopy(nums, 0, newNums, 1, len);
        // 虚拟边界设为1
        int newLen = newNums.length;
        newNums[0] = 1;
        newNums[newLen-1] = 1;

        // 创建 dp 表
        int[][] dp = new int[newLen][newLen];

        // 开始填表
        for (int begin = newLen - 2; begin >= 0; begin--) {
            for (int end = begin + 2; end < newLen; end++) {
                // 如果begin + 1 == end，则已经划分到最小
                int max = 0;
                // k 表示要戳破的气球
                for (int k = begin+1; k < end; k++) {
                    int temp = dp[begin][k] + dp[k][end] + newNums[begin] * newNums[k] * newNums[end];
                    if (temp > max) {
                        max = temp;
                    }
                }
                // dp[i][j] 表示只考虑气球 nums[i ... j] 能获得的最大金币
                dp[begin][end] = max;
            }
        }
        return dp[0][newLen - 1];
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/
// 该题解复习了：递归、分治算法、分治算法+memo、动态规划（最优子结构）

