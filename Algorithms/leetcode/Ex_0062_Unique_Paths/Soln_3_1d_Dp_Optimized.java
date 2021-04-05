package Algorithms.leetcode.Ex_0062_Unique_Paths;

import java.util.Arrays;

class Solution_3 {
    public int uniquePaths(int m, int n) {
        int[] cur = new int[n]; // 代表当前行（即pre的上一行）每个位置到终点的不同路径数
        Arrays.fill(cur, 0, n, 1);
        // 开始从下往上逐行更新cur和pre
        // 注意r是从倒数第二行开始递减；c是从倒数第二列开始递减
        for (int r = m - 2; r >= 0; r--) {
            for (int c = n - 2; c >= 0; c--) {
                cur[c] = cur[c] + cur[c+1];
            }
        }
        return cur[0];
    }
}

// 参考（推荐）：https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/

