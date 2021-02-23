package Algorithms.leetcode.Ex_200_Number_of_Islands;

class Solution_4 {
    private int res = 0;

    public int numIslands(char[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    res += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    private void dfs(char[][] grid, int r, int c) {
        if (!inArea(grid, r, c)) {
            return;
        }
        if (grid[r][c] != '1') {
            return;
        }
        // 将正在访问的位置的值修改为「已遍历过」，防止「兜圈子」
        grid[r][c] = '2';
        // 分别访问上、下、左、有四个相邻节点
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r + 1, c);
        dfs(grid, r, c + 1);
    }

    private boolean inArea(char[][] grid, int r, int c) {
        return r >= 0 && r < grid.length && c >= 0 && c < grid[0].length;
    }
}

// 参考题解：https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-/
// 题解采用的是「先污染后治理」的方法 ———— 将越界处理给下一层递归的开始时判断
// 网格结构本质上是图，因为同一个节点「同时」是其四个方向上相邻节点的「孩子」，所以在 dfs 遍历时一定要避免重复遍历！不然在网格上的 dfs 很可能会不停的「兜圈子」
// 最有效的避免「兜圈子」的解决方案是：
//  1. 利用定义 visited 来空间换时间，或者
//  2. 每次访问后，直接将原 grid 上正在访问的位置修改为特殊址


