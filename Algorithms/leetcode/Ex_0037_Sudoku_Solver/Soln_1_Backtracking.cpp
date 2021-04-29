#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::unordered_set;

class Solution_1 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = (m == 0) ? 0 : board[0].size();
        if (m == 0 || n == 0) {
            return;
        }

        // 记录每一行所包含的数字 set
        // key: row number
        // value: 该行所包含的数字 set
        unordered_map<int, unordered_set<int>> rows;
        // 记录每一列所包含的数字 set
        // key: column number
        // value: 该列所包含的数字 set
        unordered_map<int, unordered_set<int>> cols;
        // 记录每一个 3x3 中所包含的数字 set
        // key: 第几个 3x3 (序号先水平递增，再垂直递增)
        // e.g.
        // [1] [2] [3]
        // [4] [5] [6]
        // [7] [8] [9]
        unordered_map<int, unordered_set<int>> grids3x3;

        
        // 初始化上面三个 map
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    // 这里需要将 char -> int
                    int num = board[i][j] - '1' + 1;
                    // 检查是否是第一次到当前行
                    rows[i].insert(num);
                    cols[j].insert(num);
                    grids3x3[grids3x3Transform(i, j)].insert(num);
                }
            }
        }

        // 从左上角开始，尝试用 1~9 每个数字填充每个 . 字符
        bool completed = false;
        backtracking(board, 0, 0, m, n, rows, cols, grids3x3, completed);

    }

private:
    // 通过行号和列号，得到当前在第几个 3x3 grid
    int grids3x3Transform(int r, int c) {
        return r / 3 * 3 + c / 3;
    }

    // 这里回溯采用：不管三七二十一先递归到下一层，然后再根据 r, c 值判断是否需要换行
    void backtracking(vector<vector<char>> &board, int r, int c, int m, int n, unordered_map<int, unordered_set<int>> &rows, unordered_map<int, unordered_set<int>> &cols, unordered_map<int, unordered_set<int>> &grids3x3, bool &completed) {
        // base case
        if (completed) {
            return;
        }
        if (r == m - 1 && c == n) {
            // 走到了右下角的右边一格，说明已经完成了 board 上所有空白位的填写
            completed = true;
            return;
        }

        // 检测是否需要换行
        if (c == n) {
            r ++;
            c = 0;
        }
        // 检测当前位是否为空白
        if (board[r][c] != '.') {
            // 继续往右递归一位
            backtracking(board, r, c + 1, m, n, rows, cols, grids3x3, completed);
        } else {
            // 用 1~9 每个数字尝试填写当前位置
            for (int i = 1; i <= 9; i++) {
                // 检查当前行是否有数字 i
                if (rows[r].count(i)) {
                    continue;
                }
                // 检查当前列是否有数字 i
                if (cols[c].count(i)) {
                    continue;
                }
                // 检查当前 3x3 格子是否有数字 i
                if (grids3x3[grids3x3Transform(r, c)].count(i)) {
                    continue;
                }

                // 开始回溯
                // 1. 修改当前节点的状态
                board[r][c] = ('1' - 1) + i;    // 注意这需要用字符，不能直接将 i 赋给 board[r][c]
                rows[r].insert(i);
                cols[c].insert(i);
                grids3x3[grids3x3Transform(r, c)].insert(i);

                // 2. 递归子节点
                backtracking(board, r, c + 1, m, n, rows, cols, grids3x3, completed);

                // 如果已经填完所有数字，就不要恢复状态了，否则就恢复初始状态了
                if (completed) {
                    return;
                }

                // 3. 恢复当前节点的状态
                grids3x3[grids3x3Transform(r, c)].erase(i);
                cols[c].erase(i);
                rows[r].erase(i);
                board[r][c] = '.';
            }
        }
    }

};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
