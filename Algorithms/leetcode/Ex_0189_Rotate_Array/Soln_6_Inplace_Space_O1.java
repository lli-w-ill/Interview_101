package Algorithms.leetcode.Ex_0189_Rotate_Array;

class Solution_6 {
    public void rotate(int[] nums, int k) {
        
        int length = nums.length;
        k %= length;

        // 特判
        if (k == 0 || length == 1) {
            return;
        }

        // 我理解的是 times 类似与是一种赋过值和还未赋值的一种比例
        int times = 1;

        for (int i = 0; i < times; i++) {
            int index = i;
            int hold = nums[index];
            int count = 0;  // 记录本轮（即考虑 index, (index+k)%length, (index+2k)%length, ...）赋值给下一个位置时的交换总次数

            while (index != i || hold == nums[index]) {
                index = (index + k) % length;
                hold = swap(nums, hold, index);
                count ++;
            }

            times = length / count;
        }
    }

    // 将 hold 的值赋值给下标 index，注意需要返回赋值前 nums[index] 的值，以备份为下一次赋值做准备
    private int swap(int[] nums, int hold, int index) {
        int backup = nums[index];
        nums[index] = hold;
        return backup;    // 注意：这里不是直接给 nums[j] 赋值，而是返回
    }
}

// 参考题解下方评论 @如也 下的回复 @lora-h 提供的 O(1) 空间解法：https://leetcode-cn.com/problems/rotate-array/solution/javadai-ma-3chong-fang-shi-tu-wen-xiang-q8lz9/

