#include <vector>
#include <string>

using std::vector;
using std::string;
using std::max;

class Solution_4 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // dp[i][j] 表示 text1[0 ... i-1] 和 text2[0 ... j-1] 的最长公共子序列的长度
        vector<vector<int>> dp (m + 1, vector<int> (n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
