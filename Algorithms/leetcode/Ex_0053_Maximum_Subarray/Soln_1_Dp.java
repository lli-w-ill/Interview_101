package Algorithms.leetcode.Ex_53_Maximum_Subarray;

class Solution_1 {
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return Integer.MIN_VALUE;
        }
        int[] maxSubSum = new int[nums.length];
        maxSubSum[0] = nums[0];
        int max = maxSubSum[0];
        for (int i = 1; i < nums.length; i++) {
            maxSubSum[i] = Math.max(nums[i], maxSubSum[i - 1] + nums[i]);
            max = Math.max(maxSubSum[i], max);
        }
        return max;
    }
}