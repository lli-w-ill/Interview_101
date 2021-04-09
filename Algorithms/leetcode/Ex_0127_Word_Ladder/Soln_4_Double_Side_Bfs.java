package Algorithms.leetcode.Ex_0127_Word_Ladder;

import java.util.List;
import java.util.Set;
import java.util.HashSet;

class Solution_4 {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        if (wordSet.size() == 0 || !wordSet.contains(endWord)) {
            return 0;
        }

        // 已访问过的 word
        Set<String> visited = new HashSet<>();
        // 用从 beginWord 开始 BFS 扩散，和从 endWord 开始 BFS 扩散的两个哈希set 代替之前的 queue
        Set<String> beginVisited = new HashSet<>();
        Set<String> endVisited = new HashSet<>();
        beginVisited.add(beginWord);
        endVisited.add(endWord);

        // 开始执行双向 BFS
        int distance = 1;
        while (!beginVisited.isEmpty() && !endVisited.isEmpty()) {
            // 优先选择小的哈希set 进行扩散，考虑到的情况（遍历的单词数）较少
            if (beginVisited.size() > endVisited.size()) {
                Set<String> temp = beginVisited;
                beginVisited = endVisited;
                endVisited = temp;
            }

            // 从 beginVisited 中的单词开始扩散
            Set<String> nextLevelVisited = new HashSet<>();
            for (String word : beginVisited) {
                if (changeWordEveryOneLetter(word, endVisited, visited, wordSet, nextLevelVisited)) {
                    return distance + 1;
                }
            }

            // 更新哈希set
            beginVisited = nextLevelVisited;
            
            distance ++;
        }

        return 0;
    }

    private boolean changeWordEveryOneLetter(String currentWord, Set<String> endVisited, Set<String> visited, Set<String> wordSet, Set<String> nextLevelVisited) {
        char[] charArray = currentWord.toCharArray();
        for (int i = 0; i < currentWord.length(); i++) {
            // 备份当前位的字符
            char originChar = charArray[i];

            for (char k = 'a'; k <= 'z'; k++) {
                if (k == originChar) {
                    continue;
                }
                charArray[i] = k;
                String nextWord = String.valueOf(charArray);
                if (wordSet.contains(nextWord)) {
                    if (endVisited.contains(nextWord)) {
                        return true;
                    }
                    if (!visited.contains(nextWord)) {
                        nextLevelVisited.add(nextWord);
                        // 把改变单个字符后的字符串标记为「已访问」
                        visited.add(nextWord);
                    }
                }
            }

            // 恢复当前位的字符
            charArray[i] = originChar;
        }

        return false;
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/word-ladder/solution/yan-du-you-xian-bian-li-shuang-xiang-yan-du-you-2/
