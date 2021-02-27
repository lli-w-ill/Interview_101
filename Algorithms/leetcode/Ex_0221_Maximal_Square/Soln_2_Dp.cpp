#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution_2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] 是以 matrix[i-1][j-1] 为右下角的最大正方形的边长
        // 目标：求dp[rows][cols]
        // 状态转移方程：dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
        // 所以，任何一个正方形，我们都「依赖」当前格 左、上、左上三个方格的情况
        // 因为第一行上面和左上没有格子了；第一列，左面和上面没有格子了，所以dp的大小需要在matrix的大小基础上上面加一行、左面加一列
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        int dp[rows+1][cols+1];
        // 初始化第一行、第一列为0
        for (int r = 0; r <= rows; r++) {
            dp[r][0] = 0;
        }
        for (int c = 0; c <= cols; c++) {
            dp[0][c] = 0;
        }

        // 开始填表
        int maxSide = 0;
        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                if (matrix[r-1][c-1] == '1') {
                    dp[r][c] = min(dp[r-1][c-1], min(dp[r-1][c], dp[r][c-1])) + 1;
                    maxSide = max(maxSide, dp[r][c]);
                } else if (matrix[r-1][c-1] == '0') {
                    dp[r][c] = 0;
                }
            }
        }

        return maxSide * maxSide;
    }
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/maximal-square/solution/li-jie-san-zhe-qu-zui-xiao-1-by-lzhlyle/
