package Algorithms.leetcode.Ex_0198_House_Robber;

class Solution_6 {
    public int rob(int[] nums) {
        int len = nums.length;
        // 特判
        if (len == 0) {
            return 0;
        }
        // dp[k] 表示偷前k个房子 nums[0 ... k-1] 能偷到最大的金额
        int[] dp = new int[len+1];
        // 定义基准情况
        dp[0] = 0;
        dp[1] = nums[0];
        // 注意一定要分析子问题的计算顺序
        // 由于分析可知 dp[k] 依赖于 dp[k-1], dp[k-2]，所以依赖关系是向右指的，所以计算顺序应该是自左向右
        for (int k = 2; k <= len; k++) {
            //               dp[k-1]: 不偷第k个房子，也就是nums[k-1]，前k个房子偷的最大金额，就是其子问题————前k-1个房子偷的最大金额
            //                        dp[k-2] + nums[k-1]: 偷第k个房子，也就是nums[k-1]，前k个房子偷的最大金额，就是其子问题——————前k-2个房子偷的最大金额 + 第k个房子的金额
            dp[k] = Math.max(dp[k-1], dp[k-2] + nums[k-1]);
        }
        return dp[len];
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap/
// 这篇题解详细介绍了思考 DP 问题的流程，强烈推荐！

