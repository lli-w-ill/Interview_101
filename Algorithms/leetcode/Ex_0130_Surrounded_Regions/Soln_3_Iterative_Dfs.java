package Algorithms.leetcode.Ex_0130_Surrounded_Regions;

import java.util.Stack;

class Position {
    public int i;
    public int j;

    Position(int i, int j) {
        this.i = i;
        this.j = j;
    }
}

class Solution_3 {
    public void solve(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }

        int m = board.length;
        int n = board[0].length;

        // 扫描第一遍
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boolean isEdge = (i == 0 || j == 0 || i == m-1 || j == n-1);
                // 从边缘的 O 开始扩散
                if (isEdge && board[i][j] == 'O') {
                    dfs(board, m, n, i, j);
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

    private void dfs(char[][] board, int m, int n, int i, int j) {
        Stack<Position> stack = new Stack<>();
        stack.push(new Position(i, j));
        
        while (!stack.isEmpty()) {
            // 取栈顶元素，不弹出
            Position cur = stack.peek();
            // 将当前位置标记为特殊位 #，代表可以从边缘的 O 连接到的 O
            board[cur.i][cur.j] = '#';

            // 上
            if (cur.i - 1 >= 0 && board[cur.i - 1][cur.j] == 'O') {
                stack.push(new Position(cur.i - 1, cur.j));
                continue;
            }
            // 下
            if (cur.i + 1 < m && board[cur.i + 1][cur.j] == 'O') {
                stack.push(new Position(cur.i + 1, cur.j));
                continue;
            }
            // 左
            if (cur.j - 1 >= 0 && board[cur.i][cur.j - 1] == 'O') {
                stack.push(new Position(cur.i, cur.j - 1));
                continue;
            }
            // 右
            if (cur.j + 1 < n && board[cur.i][cur.j + 1] == 'O') {
                stack.push(new Position(cur.i, cur.j + 1));
                continue;
            }

            // 当当前位所有的邻居都访问过后，再将当前位从栈中移除
            stack.pop();
        }
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/surrounded-regions/solution/bfsdi-gui-dfsfei-di-gui-dfsbing-cha-ji-by-ac_pipe/

