package Algorithms.leetcode.Ex_85_Maximal_Rectangle;

class Solution_1 {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }
        // 保存以当前数字结尾的连续 1 的个数
        int[][] width = new int[matrix.length][matrix[0].length];
        int maxArea = 0;
        // 遍历每行
        for (int row = 0; row < matrix.length; row++) {
            for (int col = 0; col < matrix[0].length; col++) {
                if (matrix[row][col] == '1') {
                    if (col == 0) {
                        width[row][col] = 1;
                    } else {
                        width[row][col] = width[row][col - 1] + 1;
                    }
                } else {
                    width[row][col] = 0;
                }
                // 记录所有行中最小的数
                int minWidth = width[row][col];
                // 向上扩展行
                for (int upRow = row; upRow >= 0; upRow--) {
                    int height = row - upRow + 1;
                    // 找到最小的数作为矩阵的宽
                    minWidth = Math.min(minWidth, width[upRow][col]);
                    maxArea = Math.max(maxArea, height * minWidth);
                }
            }
        }
        return maxArea;
    }
}

// 参考：https://leetcode-cn.com/problems/maximal-rectangle/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-1-8/
