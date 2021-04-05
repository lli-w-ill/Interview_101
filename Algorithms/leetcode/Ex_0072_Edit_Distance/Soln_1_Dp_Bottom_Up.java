package Algorithms.leetcode.Ex_0072_Edit_Distance;

class Solution_1 {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int[][] dp = new int[len1+1][len2+1];   // 行列都+1是因为为word1和word2的最前面都加上一个相同的字符（参考解法图表）
        // 初始化第一行
        dp[0][0] = 0;
        for (int c = 1; c <= len2; c++) {
            dp[0][c] = dp[0][c-1] + 1;
        }
        // 初始化第一列
        for (int r = 1; r <= len1; r++) {
            dp[r][0] = dp[r-1][0] + 1;
        }
        // 自底向上填表 （从(1,1)到(len1+1, len2+1)）
        for (int r = 1; r <= len1; r++) {       // 下面注解：r = i
            for (int c = 1; c <= len2; c++) {   // 下面注解：c = j
                if (word1.charAt(r-1) == word2.charAt(c-1)) {   // -1因为在word1和word2最前面加了一个相同字符
                    dp[r][c] = dp[r-1][c-1];
                } else {
                    dp[r][c] = Math.min(dp[r-1][c], Math.min(dp[r][c-1], dp[r-1][c-1])) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
}

// 解法参考（非常推荐）：https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/
// 如何思考 DP 问题，参考（强烈推荐）：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
// 状态：dp[i][j] 表示从 word1[0...i] 转换到 word2[0...j] 所需要的最少步数
// 问题最终求的是 dp[word1.length-1][word2.length-1]
// 状态转移方程：
// （分类讨论） 当 word1[i] == word2[j] 时，dp[i][j] = dp[i-1][j-1]
//            当 word1[i] != word2[j] 时，dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
// 注：     dp[i-1][j-1]表示替换；  dp[i-1][j]表示删除word1中的一个字符；   dp[i][j-1]表示在word1中插入一个字符
// word1:      abc -> adc                   abc -> ac                            ac -> adc
// word2:         adc                           ac                                   adc

