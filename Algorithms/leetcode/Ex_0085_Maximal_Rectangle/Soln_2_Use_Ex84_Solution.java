package Algorithms.leetcode.Ex_0085_Maximal_Rectangle;

import java.util.Deque;
import java.util.ArrayDeque;

class Solution_2 {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }
        int[] heights = new int[matrix[0].length]; // 记录每列的高度
        int maxArea = 0;
        for (int row = 0; row < matrix.length; row++) {
            // 遍历每一列，更新高度
            for (int col = 0; col < matrix[0].length; col++) {
                if (matrix[row][col] == '1') {
                    heights[col] += 1;
                } else {
                    heights[col] = 0;
                }
            }
            // 调用84题解法
            maxArea = Math.max(maxArea, this.largestRectangleArea(heights));
        }
        return maxArea;
    }

    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return heights[0];
        }
        int res = 0;
        int[] newHeights = new int[len + 2];
        // 首尾加入两个最低高度的哨兵，中间部分直接拷贝heights
        newHeights[0] = 0;
        newHeights[len + 1] = 0;
        System.arraycopy(heights, 0, newHeights, 1, len);
        heights = newHeights;
        len = len + 2;

        Deque<Integer> stack = new ArrayDeque<Integer>(len);
        // 先放入哨兵
        stack.offerLast(0);
        for (int i = 1; i < len; i++) {
            // 如果当前柱子的高度要矮于上一个数字的高度时，上一个柱子的宽度就可以被确定下来，就可以计算其面积
            while (heights[i] < heights[stack.peekLast()]) {
                // 上一个柱子的高度
                int curHeight = heights[stack.pollLast()];
                // 计算上一个柱子构成矩形的宽度
                int curWidth = i - stack.peekLast() - 1;
                res = Math.max(res, curHeight * curWidth);
            }
            stack.addLast(i);
        }
        return res;
    }
}

// 参考：https://leetcode-cn.com/problems/maximal-rectangle/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-8/
// 参考：Ex84题的哨兵解法https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/
