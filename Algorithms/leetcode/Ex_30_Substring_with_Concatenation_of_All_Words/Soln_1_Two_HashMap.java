package Algorithms.leetcode.Ex_30_Substring_with_Concatenation_of_All_Words;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

class Solution_1 {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<Integer>();
        int wordNum = words.length;
        if (wordNum == 0) {
            return res;
        }
        int wordLen = words[0].length();
        // allWords存放所有备选单词的出现次数
        HashMap<String, Integer> allWords = new HashMap<String, Integer>();
        for (String w : words) {
            int freq = allWords.getOrDefault(w, 0);
            allWords.put(w, freq + 1);
        }
        // 遍历s的所有子串
        for (int i = 0; i < s.length() - wordNum * wordLen + 1; i++) { // 注意停止循环条件：要留给足够空间给所有备选单词
            // hasWords存放当前扫描的子串含有的单词
            HashMap<String, Integer> hasWords = new HashMap<String, Integer>();
            int num = 0; // 已经匹配过的单词数
            while (num < wordNum) {
                String word = s.substring(i + num * wordLen, i + (num + 1) * wordLen);
                // 判断word是否在allWords备选单词中
                if (allWords.containsKey(word)) {
                    int freq = hasWords.getOrDefault(word, 0);
                    hasWords.put(word, freq + 1);
                    // 判断当前匹配的word出现次数是否超过了word在备选单词中给的次数
                    // 如果超过了，则这个当前子串匹配失败
                    if (hasWords.get(word) > allWords.get(word)) {
                        break;
                    }
                } else {
                    // 如果word没有在备选单词中，则匹配失败
                    break;
                }
                num += 1;
            }
            if (num == wordNum) {
                res.add(i);
            }
        }
        return res;
    }
}

// 参考：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-6/
// 参考：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
