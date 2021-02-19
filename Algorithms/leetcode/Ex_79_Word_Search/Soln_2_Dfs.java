package Algorithms.leetcode.Ex_79_Word_Search;

class Solution_2 {
    private boolean[][] marked;
    private int[][] direction;
    private int rows;
    private int cols;
    private String word;
    private char[][] board;

    public boolean exist(char[][] board, String word) {
        rows = board.length;
        if (rows == 0) {
            return false;
        }
        cols = board[0].length;
        marked = new boolean[rows][cols];   // 如果cell已经走过，则标记为true；如果cell还没有走过，则默认为false
        direction = new int[][] {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 顺序：上 -> 左 -> 下 -> 右
        this.word = word;       // 将board和word设为类成员，是为了节省传参需要的空间？？
        this.board = board;
        // 开始dfs搜索
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(int r, int c, int wordIdx) {    // wordIdx 同 C++ 解法，表示现在正在检查 word 字符的第几个下标
        if (wordIdx == word.length() - 1) {
            // 正在检查最后一个字符
            return board[r][c] == word.charAt(wordIdx);
        }
        if (board[r][c] == word.charAt(wordIdx)) {
            marked[r][c] = true;    // 标记当前cell已经走过，防止“回头”
            for (int k = 0; k < 4; k++) {
                int newR = r + direction[k][0];
                int newC = c + direction[k][1];
                if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && !marked[newR][newC]) {
                    if (dfs(newR, newC, wordIdx + 1)) {
                        return true;
                    }
                }
            }
            marked[r][c] = false;   // 恢复状态（回溯） 
        }
        return false;
    }
}

// 题解参考（推荐）：https://leetcode-cn.com/problems/word-search/solution/zai-er-wei-ping-mian-shang-shi-yong-hui-su-fa-pyth/

