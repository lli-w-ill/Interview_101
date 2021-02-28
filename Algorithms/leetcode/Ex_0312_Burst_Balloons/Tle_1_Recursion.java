package Algorithms.leetcode.Ex_0312_Burst_Balloons;

class Tle_1 {
    private int maxCoins = 0;

    public int maxCoins(int[] nums) {
        maxCoins(nums, 0, nums.length, 0);
        return maxCoins;
    }

    // beforeCoins 到目前层为止积攒的硬币数
    private void maxCoins(int[] nums, int depth, int len, int beforeCoins) {
        // System.out.print(Arrays.toString(nums));
        // System.out.println(beforeCoins);
        if (depth == len) {
            if (beforeCoins > maxCoins) {
                maxCoins = beforeCoins;
            }
            return;
        }
        // 尝试该层所有可以走的路径
        for (int i = 0; i < len; i++) {
            if (nums[i] == -1) {
                continue;
            }
            
            // 找到其左边第一个未访问过的气球
            int beforeIdx = i - 1;
            while (beforeIdx >= 0 && nums[beforeIdx] == -1) {
                beforeIdx -= 1;
            }
            int beforeNum;
            if (beforeIdx == -1) {
                // 说明左边的气球都被戳破了
                beforeNum = 1;
            } else {
                beforeNum = nums[beforeIdx];
            }

            // 找到其右边第一个未访问过的气球
            int afterIdx = i + 1;
            while (afterIdx < len && nums[afterIdx] == -1) {
                afterIdx += 1;
            }
            int afterNum;
            if (afterIdx == len) {
                // 说明右边的气球都被戳破了
                afterNum = 1;
            } else {
                afterNum = nums[afterIdx];
            }

            // 计算戳破当前气球所得的coin
            int currentCoins = beforeNum * nums[i] * afterNum;
            
            // 递归前保存下当前的起点值，在最后回溯时需要赋回来
            int curVal = nums[i];
            // 将起点值设为-1，标记为访问过
            nums[i] = -1;

            // 递归下一层
            maxCoins(nums, depth + 1, len, beforeCoins + currentCoins);
            
            // 回溯（恢复状态）
            nums[i] = curVal;
        }
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/
// 时间复杂度：O(n!)

