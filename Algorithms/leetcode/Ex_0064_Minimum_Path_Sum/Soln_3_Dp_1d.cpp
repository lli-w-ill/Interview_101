#include <vector>

using std::vector;
using std::min;

class Solution_3 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = (m == 0) ? 0 : grid[0].size();

        // dp[i] 记录的是上一行（第 i-1 行）从(0,0)到(i-1,j)为止的最短路径和
        vector<int> dp (n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    // base case (最左上的点)
                    dp[j] = grid[i][j];
                } else if (i == 0) {
                    // 第一行
                    dp[j] = dp[j-1] + grid[i][j];
                } else if (j == 0) {
                    // 第一列
                    dp[j] = dp[j] + grid[i][j];
                } else {
                    // 状态转移方程: dp[j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
                    // 这里由于每行是从左至右更新的，所以当更新到 dp[j] 时，dp[j-1] 已经是更新过的值了，而每一行的第一列会由上面的 else if 进行更新
                    dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
                }
            }
        }

        return dp[n-1];

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
