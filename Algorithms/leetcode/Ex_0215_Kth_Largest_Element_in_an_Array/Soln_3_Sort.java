package Algorithms.leetcode.Ex_0215_Kth_Largest_Element_in_an_Array;

import java.util.Arrays;

class Solution_3 {
    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        Arrays.sort(nums);
        return nums[len - k];
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/partitionfen-er-zhi-zhi-you-xian-dui-lie-java-dai-/
// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
