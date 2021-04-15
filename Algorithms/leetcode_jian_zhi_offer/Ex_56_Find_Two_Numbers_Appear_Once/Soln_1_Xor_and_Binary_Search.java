package Algorithms.leetcode_jian_zhi_offer.Ex_56_Find_Two_Numbers_Appear_Once;

class Solution_1 {
    public int[] singleNumbers(int[] nums) {
        int sum = 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int zeroCount = 0;

        for (int num : nums) {
            if (num == 0) {
                zeroCount ++;
            }
            min = Math.min(min, num);
            max = Math.max(max, num);
            sum ^= num;
        }
        // 当答案其中一个是 0 的情况下，需要特判
        if (zeroCount == 1) {
            return new int[] {sum, 0};
        }

        // 开始二分法找 r
        int lo = min;
        int hi = max;
        while (lo <= hi) {
            // 计算 mid 需要注意 lo 和 hi 的正负号，防止下标越界
            int mid;
            if (lo < 0 && hi > 0) {
                mid = (lo + hi) >> 1;
            } else {
                mid = lo + (hi - lo) / 2;
            }

            // 将 nums 分为 <=mid 和 >mid 两个数组，并分别计算异或和
            int loSum = 0;
            int hiSum = 0;
            for (int num : nums) {
                if (num <= mid) {
                    loSum ^= num;
                } else {
                    hiSum ^= num;
                }
            }

            // 根据 loSum 和 hiSum 分类讨论
            if (loSum != 0 && hiSum != 0) {
                // 两个仅出现一次的数字分别出现在了 <=mid 和 >mid 两个数组中
                return new int[] {loSum, hiSum};
            } else if (loSum == 0) {
                // mid 太小了
                lo = mid + 1;
            } else if (hiSum == 0) {
                // mid 太大了
                hi = mid - 1;
            }
        }

        return null;
    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/shi-yao-zhe-ti-huan-ke-yi-yong-er-fen-cha-zhao-bi-/

