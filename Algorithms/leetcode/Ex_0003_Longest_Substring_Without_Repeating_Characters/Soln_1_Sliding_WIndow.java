package Algorithms.leetcode.Ex_0003_Longest_Substring_Without_Repeating_Characters;

import java.util.HashSet;

class Solution_1 {
    public int lengthOfLongestSubstring(String s) {
        int longestLen = 0;
        int left = 0; // 记录当前无重复子串的左边界index
        int right = 0; // 记录当前无重复子串的右边界index
        HashSet<Character> set = new HashSet<Character>();
        while (right < s.length()) {
            char ch = s.charAt(right);
            if (set.contains(ch)) {
                // 收缩左边界，将最左边的字符从set中删除
                set.remove(s.charAt(left));
                left += 1;
            } else {
                // 扩张右边界，将当前字符加入到set
                set.add(ch);
                right += 1;
                longestLen = Math.max(longestLen, set.size());
            }
        }
        return longestLen;
    }
}
