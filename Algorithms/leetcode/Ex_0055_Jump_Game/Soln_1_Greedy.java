package Algorithms.leetcode.Ex_0055_Jump_Game;

class Solution_1 {
    public boolean canJump(int[] nums) {
        // 从最后一个左边开始往前，每次更新最后一个能到达终点的下标
        int len = nums.length;
        if (len == 0 || len == 1) {
            return true;
        }
        // 这里设「在从后往前的视角来看」最后一个（如果从前往后的视角看就是第一个）能到达终点的下标为「好的下标」，初始值设为终点下标
        int goodIdx = len - 1;
        for (int i = len - 2; i >= 0; i--) {
            if (i + nums[i] >= goodIdx) {
                // 如果 当前下标+能跳跃的最远距离 >=「最后一个好的下标」，那么说明从当前下标能跳到这个「最后一个好的下标」，那么将「最后一个好的下标」置为当前下标
                goodIdx = i;
            }
        }
        return goodIdx == 0;
    }
}
