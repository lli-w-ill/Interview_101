package Algorithms.leetcode.Ex_3_Longest_Substring_Without_Repeating_Characters;

import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int longestLen = 0;
        int left = 0; // 记录当前无重复子串的左边界index
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                // 注意更新left需要取较大值
                left = Math.max(left, map.get(s.charAt(i)) + 1);
                // left = map.get(s.charAt(i)) + 1;
                // //这个是错的，尝试"abba"，当i指向第二个a时，left会更新为1，然而这是错误的更新!（应该更新为2，即当前的left值）
            }
            map.put(s.charAt(i), i);
            longestLen = Math.max(longestLen, i - left + 1);
        }
        return longestLen;
    }
}

// 参考：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
