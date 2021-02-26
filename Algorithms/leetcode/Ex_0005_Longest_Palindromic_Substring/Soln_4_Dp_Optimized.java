package Algorithms.leetcode.Ex_0005_Longest_Palindromic_Substring;

class Solution_4 {
    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        int maxLen = 1;
        int maxs = 0;
        // 可优化点一：事实上只用到了二维数组的右上半部分，所以可以优化空间
        boolean[][] isPalindrome = new boolean[len][len];
        char[] charArray = s.toCharArray();
        // 初始化
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
        }
        // 开始dp
        for (int end = 1; end < len; end++) {
            // 可优化点二：
            // Soln_3 填表策略采用的是自左向右，自顶向下
            // 而这里采用的策略是自左向右，自底向上
            for (int start = end - 1; start >= 0; start--) {
                // 可优化点三：
                // 优化「状态转移方程」，省去了if-else，利用了短路特性
                isPalindrome[start][end] = (charArray[start] == charArray[end])
                        && ((end - start < 3) || isPalindrome[start + 1][end - 1]);

                // 判断是否更新maxs, maxLen
                if (isPalindrome[start][end] == true && end - start + 1 > maxLen) {
                    maxLen = end - start + 1;
                    maxs = start;
                }
            }
        }
        return s.substring(maxs, maxs + maxLen);
    }
}

// 参考（非常推荐）：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
