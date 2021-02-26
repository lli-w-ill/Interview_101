package Algorithms.leetcode.Ex_494_Target_Sum;

class Solution_2 {
    public int findTargetSumWays(int[] nums, int S) {
        // 计算nums中所有元素的sum ———— 用于计算 dp 的列数
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        // 特判
        if (Math.abs(S) > Math.abs(sum)) {
            return 0;
        }
        int len = nums.length;
        // dp[i][j] 表示 nums[0 ... i] 通过+/-可以得到和为j的方法数量
        // 最终要求的是 dp[len-1][S]
        // 状态转移方程：dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j-(-nums[i])]
        //                           在第i位前用加号          对第i位前用减号
        // 注意不要忘了dp的负方向，nums中所有数字和组成的区间是 [-abs(sum), +abs(sum)]
        int[][] dp = new int[len][sum * 2 + 1];
        // 初始化 dp
        if (nums[0] == 0) {
            // 因为 nums[0 ... 0] 之间的数通过 + 或 - 都等于0
            // 这里困惑了好久，为什么纵坐标是sum？？？
            // 答：因为 dp[:][0 ... sum-1] 都是给「组合和」等于负值留的（详见参考题解的插图）
            //    dp[i][sum] 是 num[0 ... i] 之间的的数字「组合和」等于0的方法数量
            //    dp[:][sum+1 ... 2*sum] 是给「组合和」等于正直留的
            dp[0][sum] = 2;
        } else {
            dp[0][sum + nums[0]] = 1;   // 第一个数字前放正号
            dp[0][sum - nums[0]] = 1;   // 第一个数字前放负号
        }

        // 开始 dp 填表
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < 2 * sum + 1; j++) {
                // 状态转移方程：dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j-(-nums[i])]
                int left = (j - nums[i] >= 0) ? j - nums[i] : 0;
                int right = (j + nums[i] < 2 * sum + 1) ? j + nums[i] : 0;
                dp[i][j] = dp[i-1][left] + dp[i-1][right]; 
            }
        }

        return dp[len-1][sum+S];
    }
}

// 参考题解：https://leetcode-cn.com/problems/target-sum/solution/dong-tai-gui-hua-si-kao-quan-guo-cheng-by-keepal/
// 这道题配合「Ex416. 分割等和子集」一起做
