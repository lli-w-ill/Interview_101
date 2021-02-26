package Algorithms.leetcode.Ex_0004_Median_of_Two_Sorted_Arrays;

class Solution_2 {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int len = m + n;
        int left = -1; // 保存上一次循环的结果
        int right = -1; // 保存当前循环的结果
        int aStart = 0;
        int bStart = 0;
        for (int i = 0; i <= len / 2; i++) {
            left = right; // 备份上一次循环的结果
            if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) { // 这里需要保证aStart和bStart都没有越界
                right = nums1[aStart++];
            } else {
                right = nums2[bStart++];
            }
        }
        if ((len & 1) == 0) {
            // 长度为偶数
            return (left + right) / 2.0;
        } else {
            // 长度为奇数
            return right;
        }
    }
}

// 参考：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
