package Algorithms.leetcode.Ex_53_Maximum_Subarray;

class Solution_2 {
    private int max = Integer.MIN_VALUE;

    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return Integer.MIN_VALUE;
        }
        int len = nums.length;
        return divideAndConquer(nums, 0, len - 1);
    }

    private int divideAndConquer(int[] nums, int left, int right) {
        if (left > right) {
            return this.max;
        }
        int mid = left + (right - left) / 2;
        // 第一种情况：最大子序和出现在左半部分
        // 计算nums[left ... mid) 部分的最大子序和
        int leftMax = divideAndConquer(nums, left, mid - 1);
        // 第二种情况：最大子序和出现在右半部分
        // 计算nums(mid ... right] 部分的最大子序和
        int rightMax = divideAndConquer(nums, mid + 1, right);
        // 第三种情况：最大子序和横跨两部分，且包含 nums[mid]
        // 计算nums[? ... mid ... ?] 部分的最大子序和
        // 首先，从 mid 开始往左计算，计算 nums[left ... mid-1] 最大的子序和
        int spanLeftMax = 0;
        int sum = 0;
        for (int i = mid - 1; i >= left; i--) {
            sum += nums[i];
            spanLeftMax = Math.max(sum, spanLeftMax);
        }
        // 然后，从 mid 开始往右计算，计算 nums[mid+1 ... right] 最大的最大子序和
        int spanRightMax = 0;
        sum = 0; // 重置
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            spanRightMax = Math.max(sum, spanRightMax);
        }
        // 整合横跨两部分，且包含 nums[mid] 的最大子序和
        int spanMax = spanLeftMax + nums[mid] + spanRightMax;
        // 最后返回三种情况中最大的子序和
        return Math.max(spanMax, Math.max(leftMax, rightMax));
    }
}
