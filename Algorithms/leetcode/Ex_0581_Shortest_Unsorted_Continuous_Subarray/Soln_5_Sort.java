package Algorithms.leetcode.Ex_0581_Shortest_Unsorted_Continuous_Subarray;

import java.util.Arrays;

class Solution_5 {
    public int findUnsortedSubarray(int[] nums) {
        int l = nums.length;    // 无序子序例的左边界
        int r = 0;              // 无序子序列的右边界
        int[] clone = nums.clone();
        Arrays.sort(clone);
        for (int i = 0; i < clone.length; i++) {
            if (nums[i] != clone[i]) {
                l = Math.min(l, i);
                r = Math.max(r, i);
            }
        }
        return l <= r ? r - l + 1 : 0;
    }
}

// 参考题解：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/
// 思路：比较排序前后数组


