/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {

    let pt1 = m - 1;    // nums1中的当前正在比较的数字
    let pt2 = n - 1;    // nums2中的当前正在比较的数字
    let pt = m + n - 1; // 当前要填的位置的下标

    while (pt1 >= 0 && pt2 >= 0) {
        if (nums1[pt1] > nums2[pt2]) {
            nums1[pt] = nums1[pt1];
            pt1 --;
        } else {
            nums1[pt] = nums2[pt2];
            pt2 --;
        }
        pt --;
    }
    // 检查是否 nums2 中的数字还没有全部放在 nums1 中
    while (pt2 >= 0) {
        nums1[pt] = nums2[pt2];
        pt2 --;
        pt --;
    }

};

// 思路：如果从前向后比较，每次在 nums1 中插入一个数都会有一次insert操作，导致其后面的数字后移的 O(m) 操作，所以从 nums1 和 nums2 最大的数字开始比较，从 nums1 尾部向前填比较好（因为省去了移动数字的操作）
// 时间复杂度：O(m+n)

