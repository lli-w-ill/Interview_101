package Algorithms.leetcode.Ex_0189_Rotate_Array;

class Solution_5 {
    public void rotate(int[] nums, int k) {
        int hold = nums[0]; // 相当于 backup
        int index = 0;
        int length = nums.length;
        boolean[] visited = new boolean[length];

        for (int i = 0; i < length; i++) {
            index = (index + k) % length;

            if (visited[index]) {
                // index 已经访问过了，nums[index] 已经赋值给 (index + k) % length 了
                // 所以不能再赋值了，否则会原地打转
                // 直接从 index + 1 开始继续考虑赋值即可
                index = (index + 1) % length;
                hold = nums[index];
                i --;
            } else {
                // 把当前值保赋值下一个位置，但是赋值前需要先将下一个位置的值记录下来，以备份
                int backup = nums[index];
                nums[index] = hold;
                hold = backup;

                // 将当前位置为「已访问」
                visited[index] = true;
            }
        }
    }
}

// 参考题解：https://leetcode-cn.com/problems/rotate-array/solution/javadai-ma-3chong-fang-shi-tu-wen-xiang-q8lz9/
