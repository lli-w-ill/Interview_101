package Algorithms.leetcode.Ex_0416_Partition_Equal_Subset_Sum;

class Solution_2 {
    public boolean canPartition(int[] nums) {
        int len = nums.length;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        // 特判: 只有当sum是偶数时才能整分
        if ((sum & 1) == 1) {
            return false;
        }

        int subsetSum = sum / 2;
        // 创建二维数组
        // 行：代表元素的下标
        // 列：代表容量，即子集合
        // dp[i][j] = true 表示 nums[0 ... i] 的子集和（每个数只用一次）可以等于 j
        boolean[][] dp = new boolean[len][subsetSum + 1];

        // 初始化：第一个数只能让容积为他自己的背包恰好装满，第一行除了 nums[0] 列，其他行均为 0
        if (nums[0] <= subsetSum) {
            dp[0][nums[0]] = true;
        }
        
        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= subsetSum; j++) {
                // 不加上第i个数字
                dp[i][j] = dp[i-1][j];

                if (nums[i] == j) {
                    dp[i][j] = true;
                    continue;
                }
                if (nums[i] < j) {
                    // 状态转移方程
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }

        return dp[len-1][subsetSum];
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/

