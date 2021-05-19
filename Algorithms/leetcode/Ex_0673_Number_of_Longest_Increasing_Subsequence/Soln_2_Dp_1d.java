package Algorithms.leetcode.Ex_0673_Number_of_Longest_Increasing_Subsequence;

class Solution_2 {
    public int findNumberOfLIS(int[] nums) {
        int length = nums.length;

        // 特判
        if (length == 0) {
            return 0;
        }

        // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
        int[] dp = new int[length];

        // counter[i] 表示以 nums[i] 结尾的最长递增子序列的组合数量
        int[] counter = new int[length];

        // base case: 每个数字都「自构成」长度为 1 的递增子序列
        Arrays.fill(dp, 1);
        Arrays.fill(counter, 1);

        int longestLength = 0;    // 记录全局最长递增子序列的长度

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        // 更新以 nums[i] 结尾的递增子序列的最长长度
                        dp[i] = dp[j] + 1;

                        // 更新以 nums[i] 结尾的递增子序列的组合数量
                        counter[i] = counter[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        // 累加以 nums[i] 结尾的递增子序列的组合数量
                        counter[i] += counter[j];
                    }
                }
            }
            
            // 更新全局最长递增子序里的长度
            longestLength = Math.max(longestLength, dp[i]);
        }

        // 再扫描一遍 dp，累加达到全局最长递增子序列的组合数量
        int res = 0;    // 记录组合次数
        for (int i = 0; i < length; i++) {
            if (dp[i] == longestLength) {
                res += counter[i];
            }
        }

        return res;

    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/dong-tai-gui-hua-jie-zui-chang-zi-xu-lie-zi-chua-4/
