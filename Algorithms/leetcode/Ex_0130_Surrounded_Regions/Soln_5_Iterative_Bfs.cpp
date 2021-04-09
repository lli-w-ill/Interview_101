#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution_5 {
private:
    class Position {
    public:
        int i;
        int j;

        Position(int i, int j) : i{i}, j{j} {
        }

    };

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (m == 1 || n == 1) {
            return;
        }

        // 扫描第一遍
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 从边缘第一个是 O 的开始搜索
                bool isEdge = (i == 0 || j == 0 || i == m - 1 || j == n - 1);
                if (isEdge && board[i][j] == 'O') {
                    bfs(board, m, n, i, j);
                }
            }
        }

        // 扫描第二遍
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';  
                }
            }
        }

    }

private:
    void bfs(vector<vector<char>> &board, int m, int n, int i, int j) {
        queue<Position> que;
        que.push(Position(i, j));
        board[i][j] = '#';
        
        while (!que.empty()) {
            Position cur = que.front();
            que.pop();  // 与dfs不同的是，bfs可以获得完队首元素直接pop即可
            // 当前位标记为特殊位
            // board[cur.i][cur.j] = '#';

            // 上
            if (cur.i - 1 >= 0 && board[cur.i - 1][cur.j] == 'O') {
                que.push(Position(cur.i - 1, cur.j));
                board[cur.i - 1][cur.j] = '#';
            }

            // 下
            if (cur.i + 1 < m && board[cur.i + 1][cur.j] == 'O') {
                que.push(Position(cur.i + 1, cur.j));
                board[cur.i + 1][cur.j] = '#';
            }

            // 左
            if (cur.j - 1 >= 0 && board[cur.i][cur.j - 1] == 'O') {
                que.push(Position(cur.i, cur.j - 1));
                board[cur.i][cur.j - 1] = '#';
            }

            // 右
            if (cur.j + 1 < n && board[cur.i][cur.j + 1] == 'O') {
                que.push(Position(cur.i, cur.j + 1));
                board[cur.i][cur.j + 1] = '#';
            }
        }
    }
};

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/surrounded-regions/solution/bfsdi-gui-dfsfei-di-gui-dfsbing-cha-ji-by-ac_pipe/

