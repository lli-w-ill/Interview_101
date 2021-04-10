package Algorithms.leetcode.Ex_0139_Word_Break;

import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.Arrays;

class Solution_4 {
    private int len;
    private Set<String> wordSet;
    private int[] memo;

    public boolean wordBreak(String s, List<String> wordDict) {
        len = s.length();
        // 将所有单词放到一个 set 中，减少查词时的复杂度
        wordSet = new HashSet<String>();
        for (String word : wordDict) {
            wordSet.add(word);
        }
        memo = new int[len + 1];
        Arrays.fill(memo, -1);  // 初始化备忘录
        return canBreak(s, 0);
    }

    private boolean canBreak(String s, int startIdx) {
        // base case
        if (startIdx == len) {
            return true;
        }

        if (memo[startIdx] == 0) {
            // memo[i] = 0 表示 s[startIdx ... END] 之前的分支已经计算过了，不能拆分成wordSet中的单词组合
            return false;
        } else if (memo[startIdx] == 1) {
            // memo[i] = 1 表示 s[startIdx ... END] 之前的分支已经计算过了，能拆分成wordSet中的单词组合
            return true;
        } else {
            // memo[i] = -1 表示 s[startIdx ... END] 之前的分支还没有逐个取子串并与wordSet中匹配过
            for (int i = startIdx + 1; i <= len; i++) {
                // 截取 s[startIdx ... i-1]，并在 wordSet 中查找是否有
                String sub = s.substring(startIdx, i);
                if (wordSet.contains(sub) && canBreak(s, i)) {
                    // 如果 s[startIdx ... i-1] 有匹配，则继续在 s[i ... END] 中逐个截取然后检查
                    // 如果 s[i ... END] 也都匹配，则返回true
                    memo[startIdx] = 1;
                    return true;
                }
            }
            memo[startIdx] = 0;
            return false;
        }
    }
}

// 题解参考（强烈推荐）：https://leetcode-cn.com/problems/word-break/solution/shou-hui-tu-jie-san-chong-fang-fa-dfs-bfs-dong-tai/
// 对比 Tle_3
