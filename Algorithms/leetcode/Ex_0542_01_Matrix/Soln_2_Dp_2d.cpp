#include <vector>

using std::vector;
using std::min;

class Solution_2 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = (m == 0) ? 0 : mat[0].size();

        if (m == 0 || n == 0) {
            return mat;
        }

        // dp[i][j] 表示 (i, j) 距离其最近的 0 的距离
        vector<vector<int>> dp (m, vector<int> (n, INT_MAX - 1));

        // 第一轮 DP：从「左上角」到「右下角」做一次动态搜索
        // 本轮 DP 对于每一个位置 (i, j) 只考虑其从「左边」(i, j-1) 和「上边」(i-1, j) 的两个方向 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (j > 0) {
                        // 考虑「左边方向」
                        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                    }
                    if (i > 0) {
                        // 考虑「上边方向」
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    }
                }
            }
        }

        // 第二轮 DP：从「右下角」到「左上角」做一次动态搜索
        // 本轮 DP 对于每一个位置 (i, j) 只考虑其从「右边」(i, j+1) 和「下边」(i+1, j) 的两个方向
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (j + 1 < n) {
                        // 考虑「右边方向」
                        dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                    }
                    if (i + 1 < m) {
                        // 考虑「下边方向」
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    }
                }
            }
        }

        return dp;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 思路：按照相反的方向跑两轮 DP，每一轮对于每个位置，只考虑从起点向终点的两个方向
// 
// 设 m = mat.size(), n = mat[0].size()
// time complexity: O(m * n)
// space complexity: O(m * n)
