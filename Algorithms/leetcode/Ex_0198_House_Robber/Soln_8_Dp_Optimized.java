package Algorithms.leetcode.Ex_0198_House_Robber;

class Solution_8 {
    public int rob(int[] nums) {
        int len = nums.length;
        // 特判
        if (len == 0) {
            return 0;
        }
        // 定义基准情况
        int prev = 0;
        int curr = 0;
        // 注意一定要分析子问题的计算顺序
        // 每次循环计算“偷到当前房子为止的最大金额”
        for (int i : nums) {
            // 循环开始时，curr 表示 dp[k-1]，即前k-1个房子偷到的最多金额
            //           prev 表示 dp[k-2]，即前k-2个房子偷到的最多金额
            // dp[k] = Math.max(dp[k-1], dp[k-2] + nums[k-1]);
            // 首先求出前k个房子能偷到最多的金额
            //            curr: 不偷第k个房子，也就是nums[k-1]，前k个房子偷的最大金额，就是其子问题————前k-1个房子偷的最大金额
            //                  prev + i: 偷第k个房子，也就是nums[k-1]，前k个房子偷的最大金额，就是其子问题——————前k-2个房子偷的最大金额 + 第k个房子的金额
            int maxCur = Math.max(curr, prev + i);
            // 更新 prev 和 curr
            prev = curr;
            curr = maxCur;
        }
        return curr;
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/house-robber/solution/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap/
// 这篇题解详细介绍了思考 DP 问题的流程，强烈推荐！

