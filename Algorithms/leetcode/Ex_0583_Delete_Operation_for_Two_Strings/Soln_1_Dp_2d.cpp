#include <vector>
#include <string>

using std::vector;
using std::string;
using std::min;

class Solution_1 {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        // dp[i][j] 表示使得 word1[0 ... i-1] 和 word2[0 ... j-1] 相同所需要的最少的步数
        vector<vector<int>> dp (size1 + 1, vector<int> (size2 + 1, INT_MAX));

        // 初始化第一行与第一列
        for (int i = 0, j = 0; i <= size1; i++) {
            // 如果 word2[0 ... j-1] 是空，那么最少的步数就是把当前 word1[0 ... i-1] 删空
            dp[i][j] = i;
        }
        for (int j = 0, i = 0; j <= size2; j++) {
            // 如果 word1[0 ... i-1] 是空，那么最少的步数就是把当前 word2[0 ... j-1] 删空
            dp[i][j] = j;
        }

        // 开始填表
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // 两种选择：
                    //  1. 删除字符 word1[i]  ->  dp[i-1][j]
                    //  2. 删除字符 word2[j]  ->  dp[i][j-1]
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }

        return dp[size1][size2];

    }
};

// 设 N = word1.size(), M = word2.size()
// time complexity: O(N * M)
// space complexity: O(N * M)
// 注：这道题可以使用滚动数组优化空间复杂度
