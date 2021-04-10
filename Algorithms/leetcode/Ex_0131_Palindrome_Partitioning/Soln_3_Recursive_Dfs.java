package Algorithms.leetcode.Ex_0131_Palindrome_Partitioning;

import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;

class Solution_3 {
    public List<List<String>> partition(String s) {
        int len = s.length();
        List<List<String>> res = new ArrayList<>();
        if (len == 0) {
            return res;
        }

        Deque<String> stack = new ArrayDeque<>();
        char[] charArray = s.toCharArray();
        dfs(charArray, 0, len, stack, res);

        return res;
    }

    private void dfs(char[] charArray, int startPos, int len, Deque<String> path, List<List<String>> res) {
        if (startPos == len) {
            // 已经走到了叶子结点（即空字符串），说明当前path 中的所有分割串都是回文的
            // 注意：这里一定要插入一份拷贝，而不是直接将 path 加入到 res 中，因为返回上一层厚 path 会被修改
            res.add(new ArrayList<>(path));
            return;
        }

        for (int endPos = startPos; endPos < len; endPos++) {
            // 采用下标方式来避免取子串的时间复杂度
            if (!checkPalindrome(charArray, startPos, endPos)) {
                // s[startPos ... endPos] 不是回文串
                continue;
            }
            
            path.addLast(new String(charArray, startPos, endPos + 1 - startPos));

            // 继续分割剩余字符串
            dfs(charArray, endPos + 1, len, path, res);

            // 回溯
            path.removeLast();

        }
    }

    private boolean checkPalindrome(char[] charArray, int left, int right) {
        while (left < right) {
            if (charArray[left] != charArray[right]) {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/palindrome-partitioning/solution/hui-su-you-hua-jia-liao-dong-tai-gui-hua-by-liweiw/
// 设 N = s.length
// 时间复杂度：O(N * 2^N)
// 空间复杂度：O(N * 2^N)
