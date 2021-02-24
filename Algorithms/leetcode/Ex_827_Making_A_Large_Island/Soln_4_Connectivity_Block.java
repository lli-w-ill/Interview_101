package Algorithms.leetcode.Ex_827_Making_A_Large_Island;

import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

class Solution_4 {
    private int[] dr = new int[] {-1, 0, 1, 0};
    private int[] dc = new int[] {0, -1, 0, 1};

    public int largestIsland(int[][] grid) {
        int n = grid.length;
        int res = 0;
        int tag = 2;    // 岛屿编号从2开始
        // 下标表示二维数组下标的展开格式，即 row * n + col；并且数组中的值为展开下标所在岛屿的面积
        int[] area = new int[n * n + 2];     // 但这里为什么要+2？？？？？？
        // 首先对所有陆地计算其面积，并将每个岛屿置为独有的tag，而且
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    area[tag] = dfs(grid, r, c, tag);
                    tag += 1;
                }
            } 
        }
        // 在对所有海洋格子观察其四个方向
        // 首先对 res 进行初始化，即不填海时，最大岛屿的面积
        for (int x : area) {
            res = Math.max(res, x);
        }
        // 然后遍历所有 0
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    // 记录加过面积的岛屿所在的「所有」下标
                    Set<Integer> visited = new HashSet<Integer>();
                    for (Integer move : neighbors(r, c, n)) {
                        int rr = move / n;
                        int cc = move % n;
                        if (grid[rr][cc] > 1) {
                            // 即 (rr, cc) 是与 (r, c) 属于同一片岛屿
                            visited.add(grid[rr][cc]);
                        }
                    }
                    int a = 1;
                    for (int i : visited) {
                        a += area[i];
                    }
                    res = Math.max(res, a);
                }
            }
        }
        return res;
    }

    // 返回当前(r, c)所在岛屿的最大面积
    private int dfs(int[][] grid, int r, int c, int tag) {
        int area = 1;
        int n = grid.length;
        grid[r][c] = tag;   // 将属于当前岛屿的陆地设为独有 tag
        for (Integer move : neighbors(r, c, n)) {
            int rr = move / n;
            int cc = move % n;
            if (grid[rr][cc] == 1) {
                grid[rr][cc] = tag;
                area += dfs(grid, rr, cc, tag);
            }
        }
        return area;
    }

    // 返回(r, c)的四个邻居
    private List<Integer> neighbors(int r, int c, int n) {
        List<Integer> res = new ArrayList<Integer>();
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                res.add(nr * n + nc);
            }
        }
        return res;
    }
}

// 参考题解：https://leetcode-cn.com/problems/making-a-large-island/solution/zui-da-ren-gong-dao-by-leetcode/
// 连通块大小解法上述链接解释的没有这个链接（https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-/）清楚，建议配合这个链接一起理解。
// 思路：在 Tle_3 中，我们每次在遇到海洋（即0）时，都利用dfs重复第计算所有（连通）岛屿格子的面积
// 所以我们首先计算每个连通岛屿格子的面积，并将连通岛屿格子都赋值为其所在岛屿的面积，然后对每个海洋格子的上下左右的面积进行相加
// 但是注意这种情况（这里用 ~ 表示海洋，* 表示陆地）
// 在这类例子中：
//      ~  ~
//      ~  *
// 海洋格子的「上」和「左」连着相同的岛屿，所以面积不是 3 + 3 + 1
// 这就需要用对连通岛屿进行编号来解决了，详解题解算法解释
// 
// 注：这个题解读着还是觉得没有完全理解。其他题解中还有用并查集(Union Find)的解法。
