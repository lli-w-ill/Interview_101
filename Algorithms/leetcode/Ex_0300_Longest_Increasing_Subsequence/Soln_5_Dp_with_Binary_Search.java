package Algorithms.leetcode.Ex_0300_Longest_Increasing_Subsequence;

class Solution_5 {
    public int lengthOfLIS(int[] nums) {
        // tails[k] 代表长度为 k+1 的子序列尾部元素的值
        // tails 始终是递增的，并且保证tails的尾元素尽可能的小
        int[] tails = new int[nums.length];
        // res 为当前tails尾元素的位置
        int res = 0;
        for (int num : nums) {
            int i = 0;
            int j = res;
            while (i < j) {
                int mid = i + (j - i) / 2;
                if (tails[mid] < num) {
                    i = mid + 1;
                } else {
                    j = mid;
                }
            }
            tails[i] = num;
            if (res == j) {
                res += 1;
            }
        }
        return res;
    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
// 优化：通过修改状态定义，使整个 dp 为一个有序列表，从而可以修改内循环为二分法来找到 preMaxDp
