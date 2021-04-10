package Algorithms.leetcode.Ex_0139_Word_Break;

import java.util.List;
import java.util.Set;
import java.util.HashSet;
import java.util.Deque;
import java.util.ArrayDeque;

class Solution_6 {
    public boolean wordBreak(String s, List<String> wordDict) {
        int len = s.length();
        Set<String> wordSet = new HashSet<String>();
        Set<Integer> visited = new HashSet<Integer>();  // 记录哪些startIdx之前曾经已经计算过了
        // 将所有单词放到一个 set 中，减少查词时的复杂度
        for (String word : wordDict) {
            wordSet.add(word);
        }
        // 开始bfs遍历
        Deque<Integer> deque = new ArrayDeque<Integer>();
        deque.add(0);
        while (!deque.isEmpty()) {
            int startIdx = deque.pollFirst();
            
            // 防止计算重复问题（剪枝）
            if (visited.contains(startIdx)) {
                continue;
            } else {
                visited.add(startIdx);
            }

            for (int i = startIdx; i <= len; i++) { // 这里循环到len，因为substring 是 right-exclusive 的
                String sub = s.substring(startIdx, i);
                if (wordSet.contains(sub)) {
                    // s[startIdx ... i) 在 wordSet 中可以找到对应单词
                    if (i == len) {
                        // 已经匹配到了s的结尾
                        return true;
                    } else {
                        // 将下一次要匹配的开始下标入队，下一次要继续从 i 开始匹配
                        // s[i ... i+1) -> 在 wordSet 中查找
                        // s[i ... i+2) -> 在 wordSet 中查找
                        // ...
                        deque.addLast(i);
                    }
                }
            }
        }
        return false;
    }
}

// 题解参考（强烈推荐）：https://leetcode-cn.com/problems/word-break/solution/shou-hui-tu-jie-san-chong-fang-fa-dfs-bfs-dong-tai/

