package Algorithms.leetcode.Ex_0075_Sort_Colors;

class Solution_1 {
    public void sortColors(int[] nums) {
        int zeroIdx = 0; // 记录下一个要置0的下标
        int twoIdx = nums.length - 1; // 记录下一个要置2的下标
        for (int i = 0; i <= twoIdx; i++) {
            while (nums[i] == 2 && i < twoIdx) {
                // 交换
                int temp = nums[i];
                nums[i] = nums[twoIdx];
                nums[twoIdx] = temp;
                twoIdx -= 1;
            }
            while (nums[i] == 0 && i > zeroIdx) {
                // 交换
                int temp = nums[i];
                nums[i] = nums[zeroIdx];
                nums[zeroIdx] = temp;
                zeroIdx += 1;
            }
        }
    }
}
