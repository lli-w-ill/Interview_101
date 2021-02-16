package Algorithms.leetcode.Ex_10_Regular_Expression_Matching;

class Solution_3 {
    public boolean isMatch(String s, String p) {
        // 在前面加一个相同的字符，避免对dp的初始化初始步骤（很重要）
        s = " " + s;
        p = " " + p;
        int lens = s.length();
        int lenp = p.length();
        // dp[i][j] = true 表示s[0...i]与p[0...j]匹配
        boolean[][] dp = new boolean[lens + 1][lenp + 1];
        dp[0][0] = true; // s,p 都为空字符时
        char[] cs = s.toCharArray();
        char[] cp = p.toCharArray();
        for (int i = 1; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if (cs[i - 1] == cp[j - 1] || cp[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (cp[j - 1] == '*') {
                    if (cs[i - 1] != cp[j - 2] && cp[j - 2] != '.') {
                        // 这里无需判断j-2>=0, 因为题目输入的s和p保证有效，不可能出现cp[0] = '*'的情况
                        // 由于*前面的字符与cs当前字符不匹配，所以*只能让前面那个字符(即cp[j-2])消失，即匹配0次
                        dp[i][j] = dp[i][j - 2];
                    } else if (cs[i - 1] == cp[j - 2] || cp[j - 2] == '.') {
                        // * 匹配前一个字符大于一次以上，例如: a* -> a...a*
                        boolean case1 = dp[i - 1][j];
                        // * 匹配前一个字符仅一次，例如: a* -> a
                        // boolean case2 = dp[i][j-1]; // 方法一: (s=abc, p=a*bcd) -> (s=abc, p=abcd)
                        boolean case2 = dp[i - 1][j - 2]; // 方法二: (s=abc, p=a*bcd) -> (s=bc, p=bcd)
                        // * 匹配零次，例如: a* -> 空
                        boolean case3 = dp[i][j - 2];

                        dp[i][j] = case1 || case2 || case3;
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
}

// 参考：https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/