package Algorithms.leetcode.Ex_32_Longest_Valid_Parentheses;

class Solution_2 {
    public int longestValidParentheses(String s) {
        int len = s.length();
        if (len <= 1) {
            return 0;
        }
        // dp[i] 表示以s[i]作结尾的最长有效括号子串的长度
        int[] dp = new int[len];
        // 如果考虑当前字符s[i]和上一个字符s[i-1]，一共有四种情况：
        //      1. ((
        //      2. ()
        //      3. )(
        //      4. ))
        // 情况1和3都不用更新dp，因为合法的括号子串一定是以')'结尾
        // 情况2: dp[i] = dp[i-2] + 2
        // 情况4: 看在 以第一个')'结尾的括号子串的前一个字符 是否是'('
        //       如果是，则这个'('可以与第二个')'匹配: dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
        //       如果不是，则不能匹配，不更新dp
        // 注意情况2和4都需要作下标检查
        char[] charArray = s.toCharArray();
        int maxLen = 0;
        for (int i = 0; i < len; i++) {
            if (charArray[i] == ')') {
                if (i - 1 >= 0 && charArray[i-1] == '(') {    // 注意检查下标合法，（情况2）dp[i] = dp[i-2] + 2
                    if (i - 2 >= 0) {   // 检查下标合法
                        dp[i] = dp[i-2] + 2;
                    } else {
                        dp[i] = 2;  // 特例：(), ()(), ...
                    }
                } else if (i - 1 >= 0 && i - dp[i-1] - 1 >= 0 && charArray[i-dp[i-1]-1] == '(') { // 注意检查下标合法，（情况4）看在 以第一个')'结尾的括号子串的前一个字符 是否是'('
                    if (i - dp[i-1] - 2 >= 0) {   // 检查下标合法
                        dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
                    } else {
                        dp[i] = dp[i-1] + 2;    // 特例：(()), (()()), ...
                    }
                }
                if (dp[i] >= maxLen) {
                    maxLen = dp[i];
                }
            }
        }
        return maxLen;
    }
}

// 参考：https://leetcode.com/problems/longest-valid-parentheses/solution/
