package Algorithms.leetcode.Ex_0474_Ones_and_Zeroes;

class Solution_1 {
    public int findMaxForm(String[] strs, int m, int n) {
        // dp[i][j][k] 表示：使用 strs[0 ... i-1] 之间的字符串，能够使用 j 个 0 和 k 个 1 的字符串的最大数量（即最大子集size）
        // 多设置一行，表示不使用 strs 中任何字符串下的 0-1 情况
        int length = strs.length;
        int[][][] dp = new int[length + 1][m + 1][n + 1];

        // 开始填表
        // 第一行因为不使用 strs 中任何字符下，无论 j, k 如何，能达到的最大子串size 都是0，所以不需要再遍历 i=0 的情况
        for (int i = 1; i <= length; i++) {
            // 数 strs[i-1] 的 0， 1 数目
            // count[0] 表示 0 的数目
            // count[1] 表示 1 的数目
            int[] count = countZeroAndOne(strs[i-1]);

            // 考虑在 使用／不使用 当前字符串 strs[i-1] 的情况下时的最大子集所包含的字符串数量（最大子集大小）
            for (int j = 0; j <= m; j++) {      // j: 允许使用 0 的数量
                for (int k = 0; k <= n; k++) {  // k: 允许使用 1 的数量
                    // 检查如果使用 strs[i-1] 后，下标是否合法
                    if (count[0] <= j && count[1] <= k) {
                        // 如果使用 strs[i-1]，在三维表格中后两维下标合法，那么有两种可能
                        //  1. 使用 strs[i-1]   -> dp[i-1][j-count[0]][k-count[1]]
                        //  2. 不使用 strs[i-1] -> dp[i-1][j][k]
                        // 「状态转移方程」
                        dp[i][j][k] = Math.max(dp[i-1][j-count[0]][k-count[1]] + 1, dp[i-1][j][k]);
                    } else {
                        // 如果当前允许的 0-1 数目不允许使用 strs[i-1] 字符串，那么就只有一种可能，即上述的第 2 种可能
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }

        return dp[length][m][n];
    }

    private int[] countZeroAndOne(String str) {
        int[] cnt = new int[2];
        for (char c : str.toCharArray()) {
            cnt[c - '0'] ++;
        }
        return cnt;
    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/ones-and-zeroes/solution/dong-tai-gui-hua-zhuan-huan-wei-0-1-bei-bao-wen-ti/
// 设 L = strs.length
// time complexity: O(L * m * n)
// space complexity: O(L * m * n)
