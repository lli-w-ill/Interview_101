#include <vector>

using std::vector;
using std::max;
using std::min;

class Solution_3 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = (m == 0) ? 0 : matrix[0].size();

        if (m == 0 || n == 0) {
            return 0;
        }

        // dp[i][j] 表示以 (i, j) 为右下角的最大正方形边长
        // 注：为了第一行、第一列多分配一行一列
        vector<vector<int>> dp (m + 1, vector<int> (n + 1, 0));

        int maxSide = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == '1') {
                    // 状态转移方程
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

