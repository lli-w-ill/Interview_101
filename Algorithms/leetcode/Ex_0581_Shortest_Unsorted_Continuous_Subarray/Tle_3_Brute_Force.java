package Algorithms.leetcode.Ex_0581_Shortest_Unsorted_Continuous_Subarray;

class Tle_4 {
    public int findUnsortedSubarray(int[] nums) {
        int res = nums.length;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                // find min and max in nums[i ... j]
                int min = Integer.MAX_VALUE;
                int max = Integer.MIN_VALUE;
                for (int k = i; k <= j; k++) {
                    min = Math.min(min, nums[k]);
                    max = Math.max(max, nums[k]);
                }
                if ((i > 0 && nums[i-1] > min) || (j < nums.length - 1 && nums[j+1] < max)) {
                    // 没有找到这样一个 nums[i ... j]
                    continue;
                }
                // 检查 nums[0 ... i-1] 是否是升序的，且每个数字都不比 min 大
                int k = 0;
                int prev = Integer.MIN_VALUE;
                while (k < i && prev <= nums[k] && nums[k] <= min) {
                    prev = nums[k];
                    k += 1;
                }
                if (k != i) {
                    continue;
                }
                // 判断 nums[j+1, ... END] 是否是升序的，且每个数字都不比 max 小
                k = j + 1;
                while (k < nums.length && prev <= nums[k] && nums[k] >= max) {
                    prev = nums[k];
                    k += 1;
                }
                if (k == nums.length) {
                    if (i == j) {
                        // 原数组就是有序的
                        res = 0;
                        return res;
                    } else {
                        res = Math.min(res, j - i + 1);
                    }
                }
            }
        }
        return res;
    }
}

// 参考题解：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/
// 思路：对于每一个子序列 nums[i ... j]，我们检查它是否是最小的无序子序列。因此对于每一个子序列，我们求出这个子序列中的最大和最小值，并分别用 max 和 min 表示。如果 nums[0 ... i-1] 是升序的且每个元素都比 min 小，nums[j+1 ... END] 是升序的且每个元素都比 max 大，那么 nums[i...j] 就是一个可能的答案
// 时间复杂度：O(n^3)
