#include <vector>

using std::vector;

class Solution_7 {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = (m == 0) ? 0 : board[0].size();

        if (m == 0 || n == 0) {
            return;
        }

        // 从第一行和最后一行开始 run DFS
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i, m, n);
            }
            if (board[m-1][i] == 'O') {
                dfs(board, m - 1, i, m, n);
            }
        }

        // 从第一列和最后一列开始 run DFS
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, m, n);
            }
            if (board[i][n-1] == 'O') {
                dfs(board, i, n - 1, m, n);
            }
        }

        // 再扫描一遍 board
        // '#' -> 'O'
        // 非 '#' -> 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }

    }

private:
    vector<int> directions {-1, 0, 1, 0, -1};

    // 这里 DFS 采取「递归前先检查越界」的策略
    void dfs(vector<vector<char>> &board, int i, int j, int m, int n) {
        int x;
        int y;

        board[i][j] = '#';
        
        for (int k = 0; k < directions.size() - 1; k++) {
            x = i + directions[k];
            y = j + directions[k + 1];

            if (x >= 0 && x < m - 1 && y >= 0 && y < n - 1 && board[x][y] == 'O') {
                dfs(board, x, y, m, n);
            }    
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 思路：将与四个边上 'O' 相连的的位置设置为特出字符 '#'，然后重新扫描一遍 matrix，把除了 '#' 号的地方全置为 'X', 所有 '#' 置为 'O'
