package Algorithms.leetcode.Ex_0674_Longest_Continuous_Increasing_Subsequence;

class Solution_3 {
    public int findLengthOfLCIS(int[] nums) {
        int length = nums.length;

        // 特判
        if (length <= 1) {
            return length;
        }

        // dp[0] 记录奇数位结尾的「最长连续递增序列的长度」
        // dp[1] 记录偶数位结尾的「最长连续递增序列的长度」
        int[] dp = new int[2];
        // base case: 以 nums[0] 结尾的「最长连续递增序列的长度」只有 nums[0] 自己
        dp[0] = 1;

        int res = 1;    // 记录全局的最长连续递增序列的长度
        
        for (int i = 1; i < length; i++) {  // 从下标 1 开始
            // 前一个状态值都会被覆盖，需要重新初始化
            dp[i % 2] = 1;
            
            if (nums[i] > nums[i-1]) {
                // 当前状态依赖于前一个状态
                dp[i % 2] += dp[(i - 1) % 2];
            }

            res = Math.max(res, dp[i % 2]);
        }

        return res;

    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/dong-tai-gui-hua-jie-zui-chang-zi-xu-lie-zi-chua-4/
// 建议和参考题解中的其他相关题目一起做，效果会更好
