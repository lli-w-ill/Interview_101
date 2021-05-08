#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution_4 {
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
                } else if (p[j-1] == '*') {
                    // * 可以匹配零次或多次其前面的字符
                    // 由于 .* 组合可以匹配任意长度的任意字符，所以这里需要特殊考虑
                    if (j - 2 >= 0 && p[j-2] == '.') {
                        // .* 可以匹配任意长度的任意字符
                        bool oneMatch = dp[i][j-1];     // .* 相当于 .，匹配一个任意字符
                        bool anyMatch = dp[i-1][j];     // .* 匹配多个 s[i-1] 字符
                        bool zeroMatch = dp[i][j-2];    // .* 什么都不匹配（匹配空）
                        dp[i][j] = oneMatch || anyMatch || zeroMatch;
                    } else if (j - 2 >= 0 && p[j-2] != '.') {
                        // [a-z]* 组合
                        if (p[j-2] != s[i-1]) {
                            // 说明 * 号前的字符不能匹配 s[i-1]，那么为了尽可能匹配，*只能吞掉其前面的字符，即[a-z]*匹配成空串
                            dp[i][j] = dp[i][j-2];
                        } else {
                            // 说明 * 号前的字符可以匹配 s[i-1]，那么 [a-z]* 效果相当于 .*
                            bool oneMatch = dp[i][j-1];     // [a-z]* 匹配一个 p[j-2] 字符
                            bool anyMatch = dp[i-1][j];     // [a-z]* 匹配任意长度的 p[j-2] 字符
                            bool zeroMatch = dp[i][j-2];    // [a-z]* 匹配空
                            dp[i][j] = oneMatch || anyMatch || zeroMatch;
                        }
                    }
                } else {
                    // 说明 p[j-1] 既不是 . 也不是 *，所以 p[j-1] 是字符
                    if (s[i-1] == p[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[sizeS][sizeP];

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 这一版是刷题笔记中详尽改版，双重 for 循环内判断有所不同，并且为了解释刷题笔记中的判断将部分判断条件展开了
// 刷题笔记中的原版见 Soln_5_Dp_2d
