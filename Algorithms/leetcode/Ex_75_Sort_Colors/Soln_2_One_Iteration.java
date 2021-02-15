package Algorithms.leetcode.Ex_75_Sort_Colors;

class Solution_2 {
    public void sortColors(int[] nums) {
        int len = nums.length;
        if (len < 2) {
            return;
        }
        // 循环不变量
        // nums[0...zero) = 0
        // nums[zero, i) = 1
        // nums[two, len-1] = 2
        // nums[0...i) 为已经遍历过的
        // 循环终止条件：i == two，刚好上述=0,=1,=2三个区间不重不漏覆盖整个数组

        // 初始时，保证[0...zero)为空
        int zero = 0;
        // 初始时，保证[two, len-1]为空
        int two = len;
        int i = 0;
        while (i < two) {
            if (nums[i] == 0) {
                // 先交换，再递增
                swap(nums, i, zero);
                zero += 1;
                i += 1;
            } else if (nums[i] == 1) {
                i += 1;
            } else {
                // 先递减，再交换
                two -= 1;
                swap(nums, i, two);
            }
        }
    }

    private void swap(int[] nums, int i1, int i2) {
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }
}

// 参考：https://leetcode-cn.com/problems/sort-colors/solution/kuai-su-pai-xu-partition-guo-cheng-she-ji-xun-huan/
