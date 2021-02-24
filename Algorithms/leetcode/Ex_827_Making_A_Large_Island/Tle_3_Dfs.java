package Algorithms.leetcode.Ex_827_Making_A_Large_Island;

import java.util.Stack;
import java.util.Set;
import java.util.HashSet;

class Tle_3 {
    private int[] dr = new int[] {-1, 0, 1, 0};
    private int[] dc = new int[] {0, -1, 0, 1};

    public int largestIsland(int[][] grid) {
        int n = grid.length;
        int res = 0;
        boolean hasZero = false;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    hasZero = true;
                    // 暂时将当前海洋格子变为陆地格子
                    grid[r][c] = 1;
                    // 计算面积并更新
                    res = Math.max(res, dfs(grid, r, c));
                    // 恢复状态（回溯）
                    grid[r][c] = 0;
                }
            } 
        }
        return hasZero ? res : n * n;
    }

    // 返回当前(r, c)所在岛屿的最大面积
    private int dfs(int[][] grid, int r, int c) {
        int n = grid.length;
        Stack<Integer> st = new Stack<Integer>();   // 保存我们要访问的下标编号
        Set<Integer> visited = new HashSet<Integer>();  // 记录已经访问过的下标编号
        // 按每行找从左向右，逐行向下，从0开始编号，将当前位置(r, c)对应的编号加入 st 和 seen
        st.push(r * n + c);
        visited.add(r * n + c);
        // 开始 dfs
        while (!st.isEmpty()) {
            int code = st.pop();
            int rr = code / n;
            int cc = code % n;
            // 依次访问其上、左、下、右四个方向
            for (int k = 0; k < 4; k++) {
                int newr = rr + dr[k];
                int newc = cc + dc[k];
                if (!visited.contains(newr * n + newc) 
                    && inArea(grid, newr, newc) 
                    && grid[newr][newc] == 1) {
                        st.push(newr * n + newc);
                        visited.add(newr * n + newc);
                    }
            }
        }
        // 返回面积，因为每个格子就是1，所以visited的size就是面积
        return visited.size();
    }

    private boolean inArea(int[][] grid, int r, int c) {
        int n = grid.length;
        return r >= 0 && r < n && c >= 0 && c < n;
    }
}

// 参考题解：https://leetcode-cn.com/problems/making-a-large-island/solution/zui-da-ren-gong-dao-by-leetcode/
// 思路：对于每个 0，将它变成 1，然后做一次深度优先搜索计算出连通块的大小。答案就是找到的最大连通块。
// 时间复杂度：O(n^4) （超时）
// 空间复杂度：O(n^2) （stack 和 visited 的空间）

