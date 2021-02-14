package Algorithms.leetcode.Ex_30_Substring_with_Concatenation_of_All_Words;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

class Solution_2 {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<Integer>();
        int wordNum = words.length;
        if (wordNum == 0) {
            return res;
        }
        int wordLen = words[0].length();
        HashMap<String, Integer> allWords = new HashMap<String, Integer>();
        for (String w : words) {
            int freq = allWords.getOrDefault(w, 0);
            allWords.put(w, freq + 1);
        }
        // 将window移动分成 wordLen 种情况来讨论
        for (int j = 0; j < wordLen; j++) {
            HashMap<String, Integer> hasWords = new HashMap<String, Integer>();
            int num = 0; // 记录匹配过的单词书
            for (int i = j; i < s.length() - wordNum * wordLen + 1; i = i + wordLen) {
                boolean hasRemoved = false; // 用作情况三移除后，情况一继续移除
                while (num < wordNum) {
                    String word = s.substring(i + num * wordLen, i + (num + 1) * wordLen);
                    if (allWords.containsKey(word)) {
                        int freq = hasWords.getOrDefault(word, 0);
                        hasWords.put(word, freq + 1);
                        // 情况三：匹配的单词次数超了
                        if (hasWords.get(word) > allWords.get(word)) {
                            hasRemoved = true;
                            int removeNum = 0; // 记录删除单词的个数
                            // 一直移除单词，直到所有匹配的单词都不超过提供的次数为止
                            while (hasWords.get(word) > allWords.get(word)) {
                                String firstWord = s.substring(i + removeNum * wordLen, i + (removeNum + 1) * wordLen);
                                freq = hasWords.get(firstWord);
                                hasWords.put(firstWord, freq - 1);
                                removeNum += 1;
                            }
                            num = num - removeNum + 1; // 加 1 是因为已经把当前单词加入到了 allWords 中
                            i = i + (removeNum - 1) * wordLen;
                            break;
                        }
                    } else {
                        // 情况二：遇到了不匹配的单词，直接将i移动到不匹配单词后面的那个单词（这里只是移动到不匹配的这个单词，因为for循环还会移动一个单词的位移）
                        hasWords.clear();
                        i = i + num * wordLen;
                        num = 0;
                        break;
                    }
                    num += 1;
                }
                if (num == wordNum) {
                    res.add(i);
                }
                // 情况一：子串完全匹配，将上一个子串的第一个单词从hasWords中移除
                if (num > 0 && !hasRemoved) {
                    String firstWord = s.substring(i, i + wordLen);
                    int freq = hasWords.get(firstWord);
                    hasWords.put(firstWord, freq - 1);
                    num = num - 1;
                }
            }
        }
        return res;
    }
}

// 参考：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-6/
// 参考：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
