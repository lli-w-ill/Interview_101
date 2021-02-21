package Algorithms.leetcode.Ex_152_Maximum_Product_Subarray;

class Solution_3 {
    public int maxProduct(int[] nums) {
        int res = Integer.MIN_VALUE;
        int imax = 1;   // 记录nums[0 ... i]为止的最大乘积
        int imin = 1;   // 记录nums[0 ... i]为止的最小乘积
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 0) {
                // 当当前数字是负数时
                // nums[0 ... i-1] 最大乘积 * nums[i] 会得到 nums[0 ... i] 最小乘积
                // nums[0 ... i-1] 最小乘积 * nums[i] 会得到 nums[0 ... i] 最大乘积
                // 所以此时交换imax, imin
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            // 此时 如果 nums[i] < 0, imax 是 nums[0 ... i-1] 最小乘积
            //     如果 nums[i] >= 0, imax 是 nums[0 ... i-1] 最大乘积
            imax = Math.max(imax * nums[i], nums[i]);
            // 此时 如果 nums[i] < 0, imin 是 nums[0 ... i-1] 最大乘积
            //     如果 nums[i] >= 0, imin 是 nums[0 ... i-1] 最小乘积
            imin = Math.min(imin * nums[i], nums[i]);

            res = Math.max(res, imax);
        }
        return res;
    }
}

// 参考题解（推荐）：https://leetcode-cn.com/problems/maximum-product-subarray/solution/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/

