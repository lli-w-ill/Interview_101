package Algorithms.leetcode.Ex_240_Search_a_2D_Matrix_II;

class Solution_4 {
    public boolean searchMatrix(int[][] matrix, int target) {
        // 特判
        if (matrix == null || matrix.length == 0) {
            return false;
        }
        int rows = matrix.length;
        int cols = matrix[0].length;
        return searchRecursively(matrix, target, 0, 0, cols - 1, rows - 1);
    }

    // (left, up), (right, down) 分别定义了子矩阵的左上角和右下角
    private boolean searchRecursively(int[][] matrix, int target, int left, int up, int right, int down) {
        if (left > right || up > down) {
            // 当前子矩阵为空矩阵
            return false;
        } else if (target < matrix[up][left]) {
            // target 比当前子矩阵最小的值还小（每个子矩阵左上角的值，就是当前子矩阵最小的值）
            return false;
        } else if (target > matrix[down][right]) {
            // target 比当前子矩阵最大的值还大（每个子矩阵右下角的值，就是当前子矩阵最大的值）
            return false;
        }
        // 中间列坐标
        int mid = left + (right - left) / 2;
        int row = up;
        // locate row such that matrix[row-1][mid] < target < matrix[row][mid]
        while (row <= down && matrix[row][mid] <= target) {
            if (matrix[row][mid] == target) {
                return true;
            }
            row += 1;
        }
        // 在子矩阵中寻找target
        return searchRecursively(matrix, target, left, row, mid - 1, down) || searchRecursively(matrix, target, mid + 1, up, right, row - 1);
    }
}

// 参考题解：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
// searchRecursively 最后是在「左下」和「右上」两个子矩阵中搜索，这个解法不是很好理解，建议在纸上画一遍
// 以例子的示例图为例，如果target = 10
// 那么第一次call searchRecursively 时 mid = 2, row 3，所以是在这两个矩阵里找
// 第一次：left = 0, up = 0, right = 4, bottom = 4
//        row = 3
//                  mid
//                   ↓  ----------
//          1   4    7  | 11  15 |
//          2   5    8  | 12  19 |
//          3   6    9  | 16  22 |
//        ---------     ----------
// row →  | 10  13 | 14   17  24
//        | 18  21 | 23   26  30
//        ---------
// 
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
// 分析见题解

