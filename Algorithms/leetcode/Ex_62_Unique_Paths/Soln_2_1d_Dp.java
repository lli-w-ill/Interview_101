package Algorithms.leetcode.Ex_62_Unique_Paths;

import java.util.Arrays;

class Solution_2 {
    public int uniquePaths(int m, int n) {
        int[] pre = new int[n];  // 代表当前行的前一行的所有可能性（由于终点在下标，所以循环是从下往上，所以pre这里代表的是cur下一行位置到终点的不同路径数）
        Arrays.fill(pre, 0, n, 1);
        int[] cur = new int[n]; // 代表当前行（即pre的上一行）每个位置到终点的不同路径数
        Arrays.fill(cur, 0, n, 1);
        // 开始从下往上逐行更新cur和pre
        // 注意r是从倒数第二行开始递减；c是从倒数第二列开始递减
        for (int r = m - 2; r >= 0; r--) {
            for (int c = n - 2; c >= 0; c--) {
                cur[c] = pre[c] + cur[c+1];
            }
            // 填充cur的上一行之前，先把cur赋给pre，并将cur初始化————[0, 0, 0, ...., 0, 1]
            // pre = Arrays.copyOfRange(cur, 0, cur.length);    // 这里不需要copy，因为下面cur重新allocate新的空间了，所以直接把当前cur引用的数组对象赋给pre就可以
            pre = cur;
            cur = new int[n];
            Arrays.fill(cur, 0, n, 0);
            cur[n-1] = 1;
        }
        return pre[0];
    }
}

// 参考（推荐）：https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/
// 这里可以发现其实 pre 是可以省的，不好解释，画个图
// _  _  _  _  _  _  _
// _  _  _  _  _  _  _
// 1  1  1  1  1  1  1  -> cur
// 当最后一行cur初始化后，由于计算cur上一行的值是从右往左计算的，
// 而最后一列又始终是 1，所以在计算cur上一行的值时，可以复用cur，而不用将 cur 存在额外的 pre 数组中，解法见Soln_3。
