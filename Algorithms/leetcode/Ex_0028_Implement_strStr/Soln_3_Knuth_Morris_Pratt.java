package Algorithms.leetcode.Ex_0028_Implement_strStr;

class Solution_3 {
    // dp[j][c] = next
    // 0 <= j < M, j 代表当前的状态（我理解为状态链中的下标）
    // 0 <= c < 256, c 代表遇到的字符（ASCII码）
    // 0 <= next <= M, next 代表下一个状态
    // 例子：dp[4]['A'] = 3 表示：当前位于状态4，如果遇到字符A，pat应该转移到状态3
    private int[][] dp;
    // pattern string
    private String pat;

    public int strStr(String haystack, String needle) {
        // 特判
        if (haystack.equals(needle)) {
            return 0;
        }
        if (needle.equals("")) {
            return 0;
        }
        
        this.pat = needle;
        buildDp();
        return search(haystack);
    }

    private void buildDp() {
        // 通过 this.pat 构建 dp 数组
        // 需要 O(M) 时间（M = pat.length)
        int M = pat.length();
        dp = new int[M][256];
        // base case
        dp[0][pat.charAt(0)] = 1;
        // 影子状态 X，初始为 0
        int X = 0;
        // 当前状态 j 从 1 开始
        for (int j = 1; j < M; j++) {
            for (int c = 0; c < 256; c++) {
                dp[j][c] = dp[X][c];
                dp[j][pat.charAt(j)] = j + 1;
            }
            // 更新影子状态
            X = dp[X][pat.charAt(j)];
        }
    }

    private int search(String txt) {
        // 借助 dp 数组去匹配 txt
        // 需要 O(N) 时间（N = txt.length)
        int M = this.pat.length();
        int N = txt.length();
        // 当前状态 j
        int j = 0;
        for (int i = 0; i < N; i++) {
            j = dp[j][txt.charAt(i)];
            if (j == M) {
                // 当前状态位于「终止态」，返回匹配开头的索引
                return i - M + 1;
            }
        }

        return -1;
    }
}

// 参考题解（KMP算法，强烈推荐）：https://leetcode-cn.com/problems/implement-strstr/solution/kmp-suan-fa-xiang-jie-by-labuladong/
