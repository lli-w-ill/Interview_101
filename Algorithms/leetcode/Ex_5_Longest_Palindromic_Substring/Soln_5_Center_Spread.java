package Algorithms.leetcode.Ex_5_Longest_Palindromic_Substring;

import java.util.Arrays;

class Solution_5 {
    public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        int maxLen = 1;
        char[] charArray = s.toCharArray();
        String res = s.substring(0, 1);
        // 从中心开始枚举到 len-2
        for (int i = 0; i < len - 1; i++) {
            String oddStr = centerSpread(charArray, i, i); // 扩散中心为i
            String evenStr = centerSpread(charArray, i, i + 1); // 扩散中心为i,i+1
            String maxLenStr = oddStr.length() > evenStr.length() ? oddStr : evenStr;
            if (maxLenStr.length() > maxLen) {
                maxLen = maxLenStr.length();
                res = maxLenStr;
            }
        }
        return res;
    }

    private String centerSpread(char[] charArray, int start, int end) {
        // 如果 charArray.length 是奇数，则 start = end
        // 如果 charArray.length 是偶数，则 start = end - 1
        int len = charArray.length;
        while (start >= 0 && end < len) {
            if (charArray[start] == charArray[end]) {
                start -= 1;
                end += 1;
            } else {
                break;
            }
        }
        return new String(Arrays.copyOfRange(charArray, start + 1, end));
    }
}

// 参考（非常推荐）：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
