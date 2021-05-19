package Algorithms.leetcode.Ex_0674_Longest_Continuous_Increasing_Subsequence;

class Solution_1 {
    public int findLengthOfLCIS(int[] nums) {
        int length = nums.length;

        // 特判
        if (length <= 1) {
            return length;
        }

        // dp[i] 记录以 nums[i] 结尾的最长连续递增序列的长度
        int[] dp = new int[length];
        // base case: 每个数字都「自构成」一个长度为 1 的递增序列
        Arrays.fill(dp, 1);

        int res = 1;    // 记录全局的最长连续递增序列的长度

        for (int i = 1; i < length; i++) {
            if (nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
                res = Math.max(res, dp[i]);
            }
        }

        return res;

    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/dong-tai-gui-hua-jie-zui-chang-zi-xu-lie-zi-chua-4/
// 建议和参考题解中的其他相关题目一起做，效果会更好

