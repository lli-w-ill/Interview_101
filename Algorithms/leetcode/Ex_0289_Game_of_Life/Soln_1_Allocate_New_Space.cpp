#include <vector>

using std::vector;

class Solution_1 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if (rows == 0) {
            return;
        }
        int cols = board[0].size();

        // 初始化结果集
        vector<vector<int>> res (rows, vector<int> (cols, 0));

        // 逐个单元扫描 board
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int alive = countAliveCell(board, r, c, rows, cols);
                
                // 分类讨论
                if (board[r][c] == 1) {
                    // 活细胞
                    if (alive < 2) {
                        res[r][c] = 0;
                    } else if (alive == 2 || alive == 3) {
                        res[r][c] = 1;
                    } else if (alive > 3) {
                        res[r][c] = 0;
                    }
                } else {
                    // 死细胞
                    if (alive == 3) {
                        res[r][c] = 1;
                    } else {
                        res[r][c] = 0;
                    }
                }
                
            }
        }

        board = res;
    }

private:
    // 定义 8 个方向
    vector<vector<int>> directions {
        {-1, -1},   // 左上
        {-1, 0},    // 上
        {-1, 1},    // 右上
        {0, 1},     // 右
        {1, 1},     // 右下
        {1, 0},     // 下
        {1, -1},    // 左下
        {0, -1},    // 左
    };

    int countAliveCell(const vector<vector<int>> &board, int r, int c, int rows, int cols) {
        int alive = 0;
        for (const vector<int> &d : directions) {
            int newr = r + d[0];
            int newc = c + d[1];
            if (!outOfBound(newr, newc, rows, cols) && board[newr][newc] == 1) {
                alive ++;
            }
        }
        return alive;
    }

    bool outOfBound(int r, int c, int rows, int cols) {
        return r < 0 || c < 0 || r >= rows || c >= cols;
    }
};
