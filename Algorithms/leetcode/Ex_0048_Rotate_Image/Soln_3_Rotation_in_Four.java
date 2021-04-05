package Algorithms.leetcode.Ex_0048_Rotate_Image;

class Solution_3 {
    public void rotate(int[][] matrix) {
        // 循环的范围是「行」走一半，「列」随着逐渐走入内圈，也逐渐减小，最终i, j都从(0, 0)开始，与矩阵的中心的左上角结束
        // 如果matrix是方阵（即rows = cols），则矩阵中心其实就是一个值（一个点）
        // e.g. 
        //      1    2    3
        //      4   >5<   6
        //      7    8    9
        // 如果matrix不是方阵且rows > 1 && cols > 1，则矩阵中心是四个值
        // e.g.
        //      1    2    3    4
        //      5   >6<  >7<   8
        //      9  >10< >11<  12
        //     13   14   15   16
        // 如果matrix只有一行或一列，则矩阵中心只有两个值，或者一个值
        // e.g. 
        //      1   >2<  >3<   4  
        //      
        //      1   >2<   3
        // 这道题由于是方阵，所以只考虑第一种情况就可以，但是要注意n是奇数，和n是偶数的情况
        int n = matrix.length;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                // 每次交换四个值（见参考动画）
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
}

// 参考（题解很赞）：https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode-solution-vu3m/
