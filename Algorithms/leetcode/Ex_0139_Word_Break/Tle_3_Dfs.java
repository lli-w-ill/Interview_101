package Algorithms.leetcode.Ex_0139_Word_Break;

import java.util.Set;
import java.util.HashSet;
import java.util.List;

class Tle_3 {
    private int len;
    private Set<String> wordSet;

    public boolean wordBreak(String s, List<String> wordDict) {
        len = s.length();
        // 将所有单词放到一个 set 中，减少查词时的复杂度
        wordSet = new HashSet<String>();
        for (String word : wordDict) {
            wordSet.add(word);
        }
        return canBreak(s, 0);
    }

    private boolean canBreak(String s, int startIdx) {
        if (startIdx == len) {
            return true;
        }
        for (int i = startIdx + 1; i <= len; i++) {
            // 截取 s[startIdx ... i-1]，并在 wordSet 中查找是否有
            String sub = s.substring(startIdx, i);
            if (wordSet.contains(sub) && canBreak(s, i)) {
                // 如果 s[startIdx ... i-1] 有匹配，则继续在 s[i ... END] 中逐个截取然后检查
                // 如果 s[i ... END] 也都匹配，则返回true
                return true;
            }
        }
        return false;
    }
}

// 题解参考（强烈推荐）：https://leetcode-cn.com/problems/word-break/solution/shou-hui-tu-jie-san-chong-fang-fa-dfs-bfs-dong-tai/
// 超时测试用例：
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
