package Algorithms.leetcode.Ex_0215_Kth_Largest_Element_in_an_Array;

class Solution_4 {
    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        int left = 0;           // 快排左边的边界
        int right = len - 1;    // 快排右边的边界
        int target = len - k;   // 在按照升序排序后，第k大的元素的下标是len-k

        while (true) {
            // index 表示当前已经放在其最终位置数字的下标
            // 并且 nums[0 ... index) < nums[index]
            //   nums(index ... len] >= nums[index]
            int index = partition(nums, left, right);
            // System.out.println(index);
            // System.out.println(Arrays.toString(nums));
            if (index == target) {
                // 如果当前排定的元素最终位置就是我们要找的位置（即正着数第k个，倒着数第len-k个），那么就直接返回值
                return nums[index];
            } else if (index < target) {
                // 排定的元素的最终位置小于我们要求的最终位置，则收缩左边界
                left = index + 1;
            } else if (index > target) {
                // 排定的元素的最终位置大于我们要求的最终位置，则收缩右边界
                right = index - 1;
            }
        }
    }

    /**
     * 在nums[left ... right] 执行 partition操作，返回 nums[left] 在最终排序数组中应该放置的位置 j
     * 「应该被放置的位置 j 保证」
     *      1. nums[left +1 ... j] < nums[left]
     *      2. nums(j ... right] >= nums[left]
     */
    private int partition(int[] nums, int left, int right) {
        int pivot = nums[left];
        int j = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot) {
                // 将小于 pivot 的元素交换到前面
                j += 1;
                swap(nums, j, i);
            }
        }
        // 在遍历完 for 循环后，nums 现在满足 nums[left + 1 ... j] < pivot, nums(j ... right] >= pivot
        // 将 pivot 放在最终应该在的位置 j
        swap(nums, j, left);
        return j;
    }

    private void swap(int[] nums, int o1, int o2) {
        int temp = nums[o1];
        nums[o1] = nums[o2];
        nums[o2] = temp;
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/partitionfen-er-zhi-zhi-you-xian-dui-lie-java-dai-/
// 时间复杂度：O(n)
// 空间复杂度：O(1)
