package Algorithms.leetcode.Ex_0139_Word_Break;

import java.util.List;
import java.util.Set;
import java.util.HashSet;
import java.util.Deque;
import java.util.ArrayDeque;

class Tle_5 {
    public boolean wordBreak(String s, List<String> wordDict) {
        int len = s.length();
        Set<String> wordSet = new HashSet<String>();
        // 将所有单词放到一个 set 中，减少查词时的复杂度
        for (String word : wordDict) {
            wordSet.add(word);
        }
        // 开始bfs遍历
        Deque<Integer> deque = new ArrayDeque<Integer>();
        deque.add(0);
        while (!deque.isEmpty()) {
            int startIdx = deque.pollFirst();
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
// 超时测试用例：
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
// 因为没有剪枝，肯定会有很多相同的问题被重复计算过，所以超时
