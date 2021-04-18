package Algorithms.leetcode.Ex_0240_Search_a_2D_Matrix_II;

class Solution_3 {
    public boolean searchMatrix(int[][] matrix, int target) {
        // 特判
        if (matrix == null || matrix.length == 0) {
            return false;
        }
        // 在矩阵matrix的对角线进行二分搜索
        // 由于matrix可能不是方阵，所以取短的那一维的对角线进行二分搜索
        int rows = matrix.length;
        int cols = matrix[0].length;
        int shorterDim = Math.min(rows, cols);
        // 在短的那维的对角线搜索对应的行和列
        for (int i = 0; i < shorterDim; i++) {
            // 对 matrix[:][i] 纵向找（↓↓↓↓），列下标不变，行下标变
            boolean verticalFound = binarySearch(matrix, target, i, rows - 1, true);
            // 对 matrix[i][:] 横向找（→→→→），行下标不变，列下标变
            boolean horizontalFound = binarySearch(matrix, target, i, cols - 1, false);
            if (verticalFound || horizontalFound) {
                return true;
            }
        }
        return false;
    }

    private boolean binarySearch(int[][] matrix, int target, int lo, int hi, boolean vertical) {
        int rowNum = lo;
        int colNum = lo;
        while (lo <= hi) {
            int mid = lo + (int)((hi - lo) / 2);
            if (vertical) {
                // 在 mid 列进行二分搜索
                if (matrix[mid][colNum] == target) {
                    return true;
                } else if (matrix[mid][colNum] < target) {
                    // 收缩 lo，即在 mid 列的下面找
                    lo = mid + 1;
                } else if (matrix[mid][colNum] > target) {
                    // 收缩 hi，即在 mid 列的上面找
                    hi = mid - 1;
                }
            } else {
                // 在 mid 行进行二分搜索
                if (matrix[rowNum][mid] == target) {
                    return true;
                } else if (matrix[rowNum][mid] < target) {
                    // 收缩 lo，即在 mid 行的右边找
                    lo = mid + 1;
                } else if (matrix[rowNum][mid] > target) {
                    // 收缩 hi，即在 mid 行的左边找
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
}

// 参考题解：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
// 题解方法二对算法的描述没有图，看着比较难懂。这里附上我的理解
// 方法二的算法思路是：
// 如果 R 表示行数，C 表示列数，那么主函数中从 [0 ... min(R, C) - 1] 依次循环
// 在 binarySearch 函数中，因为加入了 boolean vertical 这个参数，表明现在我们是在判断在第 lo 行横着扫描（→→→→, vertical = false）还是在第 lo 列纵着扫描（↓↓↓↓, vertical = true）
// 如果是判断第 start 行（即vertical = false），那么 hi = R - 1，且判断方向是由上至下：
//      _↓  _   _   _   _   _   _   _     
//      _↓  _↓  _   _   _   _   _   _   ️
//      _↓  _↓  _↓  _   _   _   _   _   ️    VerticalFound 
//      _↓  _↓  _↓  _↓  _   _   _   _   
//      _↓  _↓  _↓  _↓  _↓  _   _   _   
// 如果是判断第 start 列（即vertical = true），那么 hi = C - 1，且方向是由左及右：                 
//      _→  _→  _→  _→  _→  _→  _→  _→
//      _   _→  _→  _→  _→  _→  _→  _→
//      _   _   _→  _→  _→  _→  _→  _→      HorizontalFound
//      _   _   _   _→  _→  _→  _→  _→
//      _   _   _   _   _→  _→  _→  _→
// 可以观察到两者的「并集」就是整个matrix，所以只要主函数中 VerticalFound, HorizontalFound 有任何一个返回true了，就代表找到了，主函数中 i 从 [0 ... min(R, C) - 1] 都遍历完了，还是没有找到，那 target 一定不在 matrix中
//
// 时间复杂度：O( log(min(m, n)!) )，最坏情况 m ≈ n，分析见题解
