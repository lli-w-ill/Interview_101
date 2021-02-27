/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    var rows = matrix.length;
    if (rows == 0) {
        return 0;
    }
    var cols = matrix[0].length;
    // console.log(matrix);

    // 找到最大的正方形边长
    // 将 matrix[r][c] 修改为以 (r, c) 为右下角的最大正方形的边长长度
    var maxSide = 0;
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            // if (matrix[r][c] === '0') {
            //     // 没有机会增加正方形的边长
            //     continue;
            // }
            if (matrix[r][c] !== '0' && r - 1 >= 0 && c - 1 >= 0) {
                // 检查左上、左边、上边三个cell的边长
                // 状态转移方程 dp[r][c] = min(dp[r-1][c-1], dp[r-1][c], dp[r][c-1]) + 1
                const temp = [parseInt(matrix[r-1][c-1]), parseInt(matrix[r][c-1]), parseInt(matrix[r-1][c])];
                matrix[r][c] = (Math.min(...temp) + 1).toString();
            }
            // 更新最大边长
            if (parseInt(matrix[r][c]) > maxSide) {
                maxSide = parseInt(matrix[r][c]);
            }
        }
    }
    // console.log(matrix);
    return maxSide * maxSide;
};
