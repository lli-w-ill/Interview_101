package Algorithms.leetcode.Ex_0354_Russian_Doll_Envelopes;

class Soln_3 {
    public int maxEnvelopes(int[][] envelopes) {
        int length = envelopes.length;

        if (length == 0) {
            return 0;
        }

        // 按照 w 升序排序
        Arrays.sort(envelopes, (a, b) -> a[0] - b[0]);

        // dp[i] 表示以第 i 个信封结尾的最多套娃次数（下文称为「最长上升序列长度」）
        int[] dp = new int[length];

        // g[i] 记录长度为 i 的最长上升子序列中的最小「信封高度」
        int[] g = new int[length];
        Arrays.fill(g, Integer.MAX_VALUE);
        g[0] = 0;

        int res = 1;    // 记录最长上升子序列的长度
        int j = 0;      // 问题：j 代表什么呢？？
        int len = 1;    // 记录当前上升子序列的最大长度

        for (int i = 0; i < length; i++) {
            if (envelopes[i][0] != envelopes[j][0]) {
                // 只有当 w 不同时（由于已升序排序，那么 envelopes[i][0] > envelopes[j][0]），才更新 g 数组

                // 限制 j < i, 保证 g 中只会出现第 i 个信封前的「历史信封」
                while (j < i) {
                    int prevLen = dp[j];    // 以「历史信封 j」为结尾的最长上升子序列的长度
                    int curH = envelopes[j][1];     // 当前「历史信封 j」的信封高度

                    if (prevLen == len) {
                        // 如果以 j 结尾的最长上升子序列长度 与 当前记录的最长上升子序列 长度一致，说明上升序列多增加一位
                        // 问题：虽然宽度 w_i > w_j，那么怎么证明高度 h_i > h_j 呢? （难道是因为下面二分法用的是「左闭右开原则」？）
                        g[len] = curH;
                        len ++;
                    } else {
                        // 保留当前最小的「信封高度」，确保之后可能有更多的信封套在外面
                        g[prevLen] = Math.min(g[prevLen], curH);
                    }
                    j++;
                }
            }

            // 二分（采用左闭右开原则）
            // g[i] 代表上升子序列长度为 i 的「最小信封高度」
            int l = 0;
            int r = len;
            while (l < r) {
                int mid = l + (r - l) / 2;
                
                if (envelopes[i][1] <= g[mid]) {
                    // 如果 mid 信封不能套娃当前信封 i，那么缩小右边界
                    r = mid;
                } else {
                    // mid 信封可以套娃当前信封 i，收缩左边界
                    l = mid + 1;
                }
            }

            // 更新 dp[i]
            dp[i] = l;

            // 更新 res
            res = Math.max(res, dp[i]);
        }

        return res;
    }
}

// 参考题解（推荐）：https://leetcode-cn.com/problems/russian-doll-envelopes/solution/zui-chang-shang-sheng-zi-xu-lie-bian-xin-6s8d/
