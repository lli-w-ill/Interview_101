package Algorithms.leetcode.Ex_5_Longest_Palindromic_Substring;

class Solution_3 {
    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        int maxLen = 1;
        int maxs = 0;
        boolean[][] isPalindrome = new boolean[len][len];
        char[] charArray = s.toCharArray();
        // 初始化
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
        }
        // 开始dp
        for (int end = 1; end < len; end++) {
            // 这里填表策略采用的是，自左向右，自顶向下
            for (int start = 0; start < end; start++) {
                if (charArray[start] != charArray[end]) {
                    isPalindrome[start][end] = false;
                } else {
                    // 首先检查[start+1][end-1]是否是有效区间，即长度大于等于2
                    if ((end - 1) - (start + 1) + 1 < 2) {
                        isPalindrome[start][end] = true;
                    } else {
                        isPalindrome[start][end] = isPalindrome[start + 1][end - 1];
                    }
                }
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
