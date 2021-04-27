package Algorithms.leetcode.Ex_0695_Max_Area_of_Island;

class Solution_2 {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 1) {
                    int a = area(grid, r, c);
                    res = Math.max(res, a);
                }
            }
        }
        return res;
    }

    private int area(int[][] grid, int r, int c) {
        if (!inArea(grid, r, c)) {
            // 下标越界，面积增量为0
            return 0;
        }
        if (grid[r][c] != 1) {
            // 当前位置不是陆地，面积增量为0
            return 0;
        }
        // 把当前位置标记为「已访问过」，防止“回头”陷入「兜圈子」
        grid[r][c] = 2;
        return 1
            + area(grid, r - 1, c)
            + area(grid, r, c - 1)
            + area(grid, r + 1, c)
            + area(grid, r, c + 1);
    }

    private boolean inArea(int[][] grid, int r, int c) {
        return r >= 0 && r < grid.length && c >= 0 && c < grid[0].length;
    }
}

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-/
// 题解中的题一起做效果更佳
// 注意这篇题解中与 Soln_1 中 dfs 返回的结果是不一样的，Soln_1 中 dfs 每次返回的是「每个岛屿整个的面积」，由于参数 area 传的是引用，所以 dfs 中 递归调用时 area 会继续累加；而这篇题解中 dfs 每次返回的是「岛屿面积的增量」，注意区分这里的区别
