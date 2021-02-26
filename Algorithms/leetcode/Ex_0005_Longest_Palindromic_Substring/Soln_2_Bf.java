package Algorithms.leetcode.Ex_0005_Longest_Palindromic_Substring;

class Solution_2 {
    public String longestPalindrome(String s) {
        // 暴力破解：美剧所有长度当于等于2的子串，逐个判断它们是否回文
        int len = s.length();
        if (len < 2) {
            return s;
        }
        int maxLen = 1; // 最长回文子串的长度
        int maxs = 0; // 最长回文子串起始点
        char[] charArray = s.toCharArray();

        // 枚举所有长度>=2的子串
        for (int start = 0; start < len - 1; start++) {
            for (int end = start + 1; end < len; end++) {
                if (end - start + 1 > maxLen && validPalindrome(charArray, start, end)) {
                    maxLen = end - start + 1;
                    maxs = start;
                }
            }
        }
        return s.substring(maxs, maxs + maxLen);
    }

    private boolean validPalindrome(char[] charArray, int start, int end) {
        while (start < end) {
            if (charArray[start] != charArray[end]) {
                return false;
            }
            start += 1;
            end -= 1;
        }
        return true;
    }
}

// 参考：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
