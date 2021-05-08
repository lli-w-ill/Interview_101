#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution_5 {
public:
    bool isMatch(string s, string p) {
        int sizeS = s.size();
        int sizeP = p.size();

        // dp[i][j] 表示 s[0 ... i-1] 是否能与正则表达式 p[0 ... j-1] 匹配
        vector<vector<bool>> dp (sizeS + 1, vector<bool> (sizeP + 1, false));
        // base case 1: 当 s 和 p 都是空串时是匹配的
        dp[0][0] = true;
        // base case 2: 由于 * 可以将其前面的字符消除（即匹配零个），所以有 dp[0][i] = dp[0][i-2]
        for (int i = 1; i <= sizeP; i++) {
            if (p[i-1] == '*') {
                // 这里只考虑 s[0 ... i-1] 是空串 且 p[i-1] 是 * 号的情况
                dp[0][i] = dp[0][i-2];
            }
        }

        // 开始填表
        for (int i = 1; i <= sizeS; i++) {
            for (int j = 1; j <= sizeP; j++) {
                if (p[j-1] == '.') {
                    // . 可以匹配任意一个字符，所以当然也可以匹配 s[i-1]
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] != '*') {
                    // 说明 p[j-1] 是字符
                    dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
                } else if (j - 2 >= 0 && p[j-2] != s[i-1] && p[j-2] != '.') {
                    // 由于*号前的字符不能与 s[i-1] 匹配，所以*只能吞掉其前面的字符
                    dp[i][j] = dp[i][j-2];
                } else {
                    // .* 组合 或 p[j-2] == s[i-1] 的 [a-z]* 组合
                    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];  // 分别对应 oneMatch, anyMatch, zeroMatch
                }
            }
        }

        return dp[sizeS][sizeP];

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
