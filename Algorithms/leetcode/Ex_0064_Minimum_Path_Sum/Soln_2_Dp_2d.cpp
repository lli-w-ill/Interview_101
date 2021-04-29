#include <vector>

using std::vector;
using std::min;

class Solution_2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = (m == 0) ? 0 : grid[0].size();

        // dp[i][j] 记录的是 从(0,0)到(i,j)为止的最短路径和
        vector<vector<int>> dp (m, vector<int> (n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    // base case (最左上的点)
                    dp[i][j] = grid[i][j];
                } else if (i == 0) {
                    // 第一行
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if (j == 0) {
                    // 第一列
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    // 状态转移方程: dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }

        return dp[m-1][n-1];

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
