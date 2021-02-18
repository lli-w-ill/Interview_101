package Algorithms.leetcode.Ex_34_Find_First_and_Last_Position_of_Element_in_Sorted_Array;

class Solution_4 {
    public int[] searchRange(int[] nums, int target) {
        int len = nums.length;
        if (len == 0) {
            return new int[] {-1, -1};
        }

        int firstPosition = findFirstPosition(nums, target, len);
        if (firstPosition == -1) {  // target 并不在 nums 中，直接返回
            return new int[] {-1, -1};
        }
        int lastPosition = findLastPosition(nums, target, len);
        return new int[] {firstPosition, lastPosition}; 
    }

    private int findFirstPosition(int[] nums, int target, int len) {
        int left = 0;
        int right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;    // 这里用的是默认的下取整
            // 给定目标值在数组中的开始位置
            if (nums[mid] < target) {
                // mid一定不是第一个位置，因为mid以及mid左边的所有元素都小于target
                // 下一轮搜索的区间是 [mid+1 ... right)
                left = mid + 1;
            } else if (nums[mid] >= target) {
                // mid有可能是最后一个位置，下一轮搜索的区间时 [left, mid]
                right = mid;
            }
        }
        // 如果target不在nums中
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }

    private int findLastPosition(int[] nums, int target, int len) {
        int left = 0;
        int right = len - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;    // 这里+1因为需要用上取整（非常重要）
            // 给定目标值在数组中的结束位置
            if (nums[mid] > target) {
                // mid一定不是最后一个位置，因为mid以及mid右边的所有元素都大于target
                // 下一轮搜索的区间是 [left, mid-1]
                right = mid - 1;
            } else if (nums[mid] <= target) {
                // mid有可能是第一个位置，下一轮搜索的区间是[mid, right]
                left = mid;
            }
        }
        // 因为在findFirstPosition中while循环后已经判断了 target 是否可能在nums，所以这里无需再判断
        return left;
    }
}

// 思路：
// 如果nums中包含target值，那么：
//      * 在二分法返回的坐标之前（不包括这个坐标），一定不会有结束的位置；
//      * 在二分法返回的坐标之后（不包括这个坐标），一定不会有开始的位置
// findFirstPosition和findLastPosition 返回left或者返回right是一样的，因为当退出while循环后，left = right
// 参考（非常推荐）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/si-lu-hen-jian-dan-xi-jie-fei-mo-gui-de-er-fen-cha/
