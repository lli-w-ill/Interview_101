package Algorithms.leetcode.Ex_0004_Median_of_Two_Sorted_Arrays;

class Solution_3 {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int left = (m + n + 1) / 2; // 要寻找的第一个数
        int right = (m + n + 2) / 2; // 要寻找的第二个数 (如果m+n是奇数，left=right)
        return (getKth(nums1, 0, m - 1, nums2, 0, n - 1, left) + getKth(nums1, 0, m - 1, nums2, 0, n - 1, right)) / 2.0;
    }

    private int getKth(int[] nums1, int start1, int end1, int[] nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1; // nums1还剩的数字个数
        int len2 = end2 - start2 + 1; // nums2还剩的数字个数
        // 如果有数组最先被排空，保证一定是nums1
        if (len1 > len2) {
            // 交换参数顺序
            return getKth(nums2, start2, end2, nums1, start1, end1, k);
        }
        // nums1被排空了
        if (len1 == 0) {
            // 返回从未排除数字算起，nums2中第k个数字
            return nums2[start2 + k - 1];
        }
        if (k == 1) {
            // 说明当前需要返回的第一小的数，直接比较nums1和nums2中当前的数字大小即可
            return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
        }
        // 防止其中一个数组剩余长度少于k/2，如果其中一个短于k/2，则直接设置为最后最后一个下标
        int mid1 = start1 + Math.min(len1, k / 2) - 1;
        int mid2 = start2 + Math.min(len2, k / 2) - 1;
        // 比较nums1和nums2当前数字大小，决定是排除nums1[start1...mid1]还是nums2[start2...mid2]
        if (nums1[mid1] > nums2[mid2]) {
            // 排除nums2[start2...mid2]
            // 接下来寻找第 (k-nums2中排除的数字个数) 即可
            int newK = k - (mid2 - start2 + 1);
            return getKth(nums1, start1, end1, nums2, mid2 + 1, end2, newK);
        } else {
            // 排除nums1[start1...mid1]
            // 接下来寻找第 (k-nums1中排除的数字个数) 即可
            int newK = k - (mid1 - start1 + 1);
            return getKth(nums1, mid1 + 1, end1, nums2, start2, end2, newK);
        }
    }
}

// 参考：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
