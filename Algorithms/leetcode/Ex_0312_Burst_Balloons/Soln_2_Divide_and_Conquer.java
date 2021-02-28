package Algorithms.leetcode.Ex_0312_Burst_Balloons;

class Solution_2 {
    private int maxCoins = 0;

    public int maxCoins(int[] nums) {
        if (nums == null) {
            return maxCoins;
        }

        // 因为要保证 nums[0] 和 nums[len-1] 被计算到，所以两头加两个虚拟边界
        int len = nums.length;
        int[] newNums = new int[len + 2];
        System.arraycopy(nums, 0, newNums, 1, len);
        // 虚拟边界设为1
        int newLen = newNums.length;
        newNums[0] = 1;
        newNums[newLen-1] = 1;

        // 创建cache
        int[][] cache = new int[newLen][newLen];

        return maxCoins(newNums, newLen, 0, newLen - 1, cache);
    }

    // cache[i][j] 保存 maxCoins(nums, len, i, j, cache) 的结果，防止重复计算
    private int maxCoins(int[] nums, int len, int beginIdx, int endIdx, int[][] cache) {
        // base cases
        if (beginIdx + 1 == endIdx) {
            // 最小子问题
            return 0;
        }
        if (cache[beginIdx][endIdx] != 0) {
            // 该子问题已经计算过，直接返回
            return cache[beginIdx][endIdx];
        }

        int max = 0;
        for (int i = beginIdx + 1; i <= endIdx - 1; i++) {    // 因为 beginIdx 和 endIdx 都不能戳破，所以遍历所有中间的下标
            int coins = maxCoins(nums, len, beginIdx, i, cache) + maxCoins(nums, len, i, endIdx, cache) + nums[beginIdx] * nums[i] * nums[endIdx];
            if (coins > max) {
                max = coins;
            }
        }
        
        // 缓存值，避免重复计算子问题
        cache[beginIdx][endIdx] = max;

        return max;
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/
// 分治算法需要思考的是：
//  1. 如何划分子问题，才能使子问题的解能用来求的原问题的解
//  2. 子问题之间最好不要有互相依赖关系，即最好保持子问题间是相互独立的
//
// 时间复杂度：

