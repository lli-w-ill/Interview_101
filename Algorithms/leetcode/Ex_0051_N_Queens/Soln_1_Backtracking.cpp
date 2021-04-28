#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution_1 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n == 0) {
            return res;
        }
        
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false);  // ↓ 记录某列是否有皇后
        vector<bool> principal_diagonal(2 * n - 1, false);  // ↘ 记录某主对角线是否有皇后（对于 n x n 的方阵一共有 2 * n - 1 个主对角线）
        vector<bool> seconary_diagonal(2 * n - 1, false);   // ↙ 记录某辅对角线是否有皇后（对于 n x n 的方阵一共有 2 * n - 1 个辅对角线）
        
        backtracking(res, board, column, principal_diagonal, seconary_diagonal, 0, n);

        return res;
    }

private:
    void backtracking(vector<vector<string>> &res, vector<string> &board, vector<bool> &column, vector<bool> &principal_diagonal, vector<bool> &seconary_diagonal, int row, int n) {
        // base case
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            // 查看当前的位置 board[row][i] 所在的列、主对角线、辅对角线上是否存在皇后
            if (column[i] || principal_diagonal[n - row + i - 1] || seconary_diagonal[row + i + 1]) {
                continue;
            }

            // 修改当前节点的状态
            board[row][i] = 'Q';
            column[i] = true;
            principal_diagonal[n - row + i - 1] = true;
            seconary_diagonal[row + i + 1] = true;

            // 递归子节点
            backtracking(res, board, column, principal_diagonal, seconary_diagonal, row + 1, n);

            // 恢复当前节点状态
            seconary_diagonal[row + i + 1] = false;
            principal_diagonal[n - row + i - 1] = false;
            column[i] = false;
            board[row][i] = '.';
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// primary diagonal, seconary diagonal: https://en.wikipedia.org/wiki/Main_diagonal
