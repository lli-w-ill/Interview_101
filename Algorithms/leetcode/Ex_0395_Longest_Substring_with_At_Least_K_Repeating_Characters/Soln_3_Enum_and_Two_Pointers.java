package Algorithms.leetcode.Ex_0395_Longest_Substring_with_At_Least_K_Repeating_Characters;

import java.util.Arrays;

class Solution_3 {
    public int longestSubstring(String s, int k) {
        int n = s.length();
        char[] charArray = s.toCharArray();
        int[] cnt = new int[26];   // 记录子串中包含的不同字符的字符类型数量。例如 "abbbbc" 就是 [1,4,1,0,0,0,0,....,0]
        int longest = 0;    // 记录结果：最长的满足条件的子串长度

        for (int p = 1; p <= 26; p++) { // 表示限定 s[j ... i] 中出现的不同字符的字符类型数量。例如当 p=2，就表示 s[j ... i] 内只允许 2 种不同的字符出现
            Arrays.fill(cnt, 0);

            // i, j 代表当前考虑的是 s[j ... i], i: 右指针；j: 左指针
            // tot 代表 s[j ... i] 区间包含不同字符的类型数量。例如 "abbbbc", tot = 3
            // sum 代表满足「出现次数不少于 k」的字符类型数量。例如 "abbbbc" k = 3, sum = 1
            for (int i = 0, j = 0, tot = 0, sum = 0; i < n; i++){
                int u = charArray[i] - 'a'; // 字符 charArray[i] 对应的下标
                cnt[u] ++;
                
                if (cnt[u] == 1) {
                    // 说明当前 charArray[i] 是第一次加入进来
                    tot ++;
                }
                if (cnt[u] == k) {
                    // 说明当前 charArray[i] 字符「已达标」
                    sum ++;
                }

                // 当 s[j ... i] 中包含的字符种类数量(tot)超过了当前所限制的字符数量(p)，需要右移左指针(j)来删掉一些字符，直到tot降至p停止右移左指针，继续右移右指针
                while (tot > p) {
                    int t = charArray[j] - 'a';
                    cnt[t] --;

                    if (cnt[t] == 0) {
                        // 如果当前 charArray[j] 在 s[j ... i] 中出现次数已经降至 0 了，就递减 tot
                        tot --;
                    }
                    if (cnt[t] == k - 1) {
                        // 如果当前 charArray[j] 降至 k-1 时，则从「已达标」变成了不达标，递减sum
                        sum --;
                    }

                    j++;
                }

                if (tot == sum) {
                    longest = Math.max(longest, i - j + 1);

                    // 如果想记录满足条件的子串，也可以在这里记录到一个 list 中

                }
            }
        }

        return longest;
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/xiang-jie-mei-ju-shuang-zhi-zhen-jie-fa-50ri1/
