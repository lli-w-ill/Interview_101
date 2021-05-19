package Algorithms.leetcode.Ex_0674_Longest_Continuous_Increasing_Subsequence;

class Solution_2 {
    public int findLengthOfLCIS(int[] nums) {
        int length = nums.length;

        // 特判
        if (length <= 1) {
            return length;
        }

        // curLen 记录当前记录的最长连续递增序列的长度
        int curLen = 1;

        int res = 1;    // 记录全局的最长连续递增序列的长度
        

        for (int i = 1; i < length; i++) {
            if (nums[i] > nums[i-1]) {
                curLen ++;
                res = Math.max(res, curLen);
            } else {
                // 重置 curLen，从当前 nums[i] 重新开始计算递增序列
                curLen = 1;
            }
        }

        return res;

    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/dong-tai-gui-hua-jie-zui-chang-zi-xu-lie-zi-chua-4/
// 建议和参考题解中的其他相关题目一起做，效果会更好

