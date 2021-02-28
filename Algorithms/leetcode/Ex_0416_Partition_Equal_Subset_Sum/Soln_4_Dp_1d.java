package Algorithms.leetcode.Ex_0416_Partition_Equal_Subset_Sum;

class Solution_4 {
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
        
        // 优化一：（对比 Soln_3）
        // 创建一维数组
        // dp[i] = true 表示 nums[0 ... i] 的子集和（每个数只用一次）可以等于 j
        boolean[] dp = new boolean[subsetSum + 1];

        // 改变一：dp[0]设为true（虽然状态不符合，但是当有一个数可以被分为一组，其他所有数分一组时，状态转移时可以的）
        dp[0] = true;

        // 初始化：第一个数只能让容积为他自己的背包恰好装满，第一行除了 nums[0] 列，其他行均为 0
        if (nums[0] <= subsetSum) {
            dp[nums[0]] = true;
        }
        
        for (int i = 1; i < len; i++) {
            // 停止条件：当前背包容量大于等于当前数字的值
            for (int j = subsetSum; j >= nums[i]; j--) {  // 改变二：这里一定要从后往前
                dp[j] = dp[j] || dp[j-nums[i]];
            }
            // 当 nums[0 ... i] 已经有子集合等于总和的一半，即 subsetSum 时，直接返回 true
            if (dp[subsetSum]) {
                return true;
            }
        }

        return dp[subsetSum];
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/
// 由于 Soln_2, Soln_3 中的状态方程在填行 i 时只考虑行 i-1，所以可以将状态数组设置成一维的「滚动数组」
// 参考题解下精评@providence解释为什么内层循环要从后往前遍历

