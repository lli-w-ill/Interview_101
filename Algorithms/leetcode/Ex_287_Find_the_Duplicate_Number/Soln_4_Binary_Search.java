package Algorithms.leetcode.Ex_287_Find_the_Duplicate_Number;


class Solution_4 {
    public int findDuplicate(int[] nums) {
        int len = nums.length;
        // 根据题意，nums中所有的数都在[left, right]之间
        int left = 1;
        int right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 数nums中有多少个数在[1, mid]之间
            int count = 0;
            for (int num : nums) {
                if (num >= 1 && num <= mid) {
                    count += 1;
                }
            }
            
            if (count > mid) {
                // 如果count > mid 说明重复元素的值一定在[1, mid]之间 ———— 抽屉原理
                // 收缩右边界
                right = mid;
            } else {
                // 否则说明重复元素的值一定在[mid+1, right]之间
                // 收缩左边界
                left = mid + 1;
            }
        }
        return left;
    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/
// 时间复杂度：O(logn * n)

