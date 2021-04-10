package Algorithms.leetcode.Ex_0131_Palindrome_Partitioning;

import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;

class Solution_4 {
    public List<List<String>> partition(String s) {
        int len = s.length();
        List<List<String>> res = new ArrayList<>();
        if (len == 0) {
            return res;
        }

        char[] charArray = s.toCharArray();
        boolean[][] dp = new boolean[len][len];

        // 用 Ex5 中使用的方法提前用动态规划检查回文串
        preprocessingEx5(charArray, dp, len);

        Deque<String> stack = new ArrayDeque<>();

        dfs(charArray, 0, len, dp, stack, res);

        return res;
    }

    private void preprocessingEx5(char[] charArray, boolean[][] dp, int len) {
        for (int right = 0; right < len; right++) {
            for (int left = 0; left <= right; left++) {
                if (charArray[left] == charArray[right] && (right - left <= 2 || dp[left+1][right-1] == true)) {
                    dp[left][right] = true;
                }
            }
        }
    }

    private void dfs(char[] charArray, int startPos, int len, boolean[][] dp, Deque<String> path, List<List<String>> res) {
        if (startPos == len) {
            // 已经走到了叶子结点（即空字符串），说明当前path 中的所有分割串都是回文的
            // 注意：这里一定要插入一份拷贝，而不是直接将 path 加入到 res 中，因为返回上一层厚 path 会被修改
            res.add(new ArrayList<>(path));
            return;
        }

        for (int endPos = startPos; endPos < len; endPos++) {
            // 采用下标方式来避免取子串的时间复杂度
            // if (!checkPalindrome(charArray, startPos, endPos)) {
            //     // s[startPos ... endPos] 不是回文串
            //     continue;
            // }
            // 由于已经使用动态规划检查了回文串的起始和终止坐标，所以可以在 O(1) 时间内查看 charArray[startPos ... endPos] 是否回文
            if (dp[startPos][endPos] == false) {
                continue;
            }
            
            path.addLast(new String(charArray, startPos, endPos + 1 - startPos));

            // 继续分割剩余字符串
            dfs(charArray, endPos + 1, len, dp, path, res);

            // 回溯
            path.removeLast();

        }
    }

    // private boolean checkPalindrome(char[] charArray, int left, int right) {
    //     while (left < right) {
    //         if (charArray[left] != charArray[right]) {
    //             return false;
    //         }
    //         left ++;
    //         right --;
    //     }
    //     return true;
    // }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/palindrome-partitioning/solution/hui-su-you-hua-jia-liao-dong-tai-gui-hua-by-liweiw/
// 设 N = s.length
// 时间复杂度：O(N * 2^N)
// 空间复杂度：O(N * 2^N)

