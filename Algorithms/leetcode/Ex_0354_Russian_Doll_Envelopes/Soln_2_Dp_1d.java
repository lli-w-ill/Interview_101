package Algorithms.leetcode.Ex_0354_Russian_Doll_Envelopes;

class Soln_2 {
    public int maxEnvelopes(int[][] envelopes) {
        int length = envelopes.length;

        if (length == 0) {
            return 0;
        }

        // 按照 w 升序排序
        Arrays.sort(envelopes, (a, b) -> a[0] - b[0]);

        // dp[i] 表示以第 i 个信封结尾的最多套娃次数
        int[] dp = new int[length];
        int res = 1;    // 记录最多套娃次数

        for (int i = 0; i < length; i++) {
            // 首先初始值一定为 1，不套任何信封
            dp[i] = 1;

            // 枚举第 i 件信封的所有前面信封
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[i][0] > envelopes[j][0] 
                    && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }

            // 更新 res
            res = Math.max(res, dp[i]);
        }

        return res;
    }
}

// 参考题解（推荐）：https://leetcode-cn.com/problems/russian-doll-envelopes/solution/zui-chang-shang-sheng-zi-xu-lie-bian-xin-6s8d/
// 设 N = envelops.length
// time complexity: O(N ^ 2)
// space complexity: O(N)
// 
// 注：为什么同样的思路 C++ 就是超时。。
