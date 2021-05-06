#include <vector>
#include <string>

using std::vector;
using std::string;
using std::min;

class Solution_3 {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        // dp[i][j] 表示 word1[0 ... i-1] -> word2[0 ... j-1] 最少的操作数
        vector<vector<int>> dp (size1 + 1, vector<int> (size2 + 1, 0));

        // 填表
        for (int i = 0; i <= size1; i++) {
            for (int j = 0; j <= size2; j++) {
                if (i == 0) {
                    // 如果 word1[0 ... i-1] 是空串，那么 word1[0 ... i-1] -> word2[0 ... j-1] 的最少操作数就等于 word2 的字符数（插入字符的次数）
                    dp[i][j] = j;
                } else if (j == 0) {
                    // 如果 word2[0 ... j-1] 是空串，那么 word1[0 ... i-1] -> word2[0 ... j-1] 的最少操作数就等于 word1 的字符数（删除字符的次数）
                    dp[i][j] = i;
                } else {
                    // 第一种情况
                    int case_1;
                    if (word1[i-1] == word2[j-1]) {
                        // 如果当前 word1[i-1] 字符与 word2[j-1] 字符相同，则无需修改
                        case_1 = dp[i-1][j-1];
                    } else {
                        // 如果当前 word1[i-1] 字符与 word2[j-1] 字符不同，那么修改 word1[i-1] 为 word2[j-1]
                        case_1 = dp[i-1][j-1] + 1;
                    }

                    // 第二种情况：在 word1 的下标 i 处插入字符 word2[j-1]  或者  删除 word2 下标 j-1 处的字符
                    int case_2 = dp[i][j-1] + 1;

                    // 第三种情况：在 word2 的下标 j 处插入字符 word1[i-1]  或者  删除 word1 下标 i-1 处的字符
                    int case_3 = dp[i-1][j] + 1;

                    dp[i][j] = min(case_1, min(case_2, case_3));
                }
            }
        }

        return dp[size1][size2];

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
