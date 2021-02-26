package Algorithms.leetcode.Ex_0005_Longest_Palindromic_Substring;

class Solution_1 {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        int len = s.length();
        if (len == 1) {
            return s;
        }

        int[] res = new int[3]; // 存储结果，第一位表示长度，第二位表示回文子串起点（闭区间），第三位表示回文子串终点（闭区间）
        // isPalindrome[m][n] = True 表示 s[m ... n] 是一个回文子串
        boolean[][] isPalindrome = new boolean[len][len];
        // 初始化 isPalindrome
        char[] charArray = s.toCharArray();
        for (int i = 0; i < len - 1; i++) {
            isPalindrome[i][i] = true; // 每个字符自己是一个回文子串
            if (charArray[i] == charArray[i + 1]) {
                // 如果当前字符和下一个字符相同，则两个一起可以组成一个回文子串
                isPalindrome[i][i + 1] = true;
                // 更新最长回文子串
                res = new int[] { 2, i, i + 1 };
            }
        }

        // sliding window + 动态规划解法
        for (int ws = 2; ws < len; ws++) { // window size
            for (int start = 0; start < len - ws; start++) {
                // 计算window内子串的右边界
                int end = start + ws;
                // 判断s[start ... end]是否是回文子串
                if (charArray[start] == charArray[end] && isPalindrome[start + 1][end - 1] == true) {
                    // 是回文子串
                    isPalindrome[start][end] = true;
                    // 根据长度，决定是否更新res
                    if (end - start + 1 > res[0]) {
                        res[0] = end - start + 1; // 更新长度
                        res[1] = start;
                        res[2] = end;
                    }
                }
            }
        }
        return s.substring(res[1], res[2] + 1); // 注意substring是right-exclusive的，所以要+1
    }
}