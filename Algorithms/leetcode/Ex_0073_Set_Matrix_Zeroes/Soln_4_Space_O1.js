/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;

    // 找第一行是否有0
    firstRowHasZero = false;
    for (let c = 0; c < cols; c++)
        if (matrix[0][c] == 0) {
            firstRowHasZero = true;
            break;
        }
    
    // 找第一列是否有0
    firstColumnHasZero = false;
    for (let r = 0; r < rows; r++)
        if (matrix[r][0] == 0) {
            firstColumnHasZero = true;
            break;
        }

    // 将第一行、第一列作为「该行／列有0的标志位」
    // 从(1,1)开始检查0
    for (let r = 1; r < rows; r++) 
        for (let c = 1; c < cols; c++)
            if (matrix[r][c] == 0) {
                matrix[0][c] = 0;
                matrix[r][0] = 0;
            }
    
    // 根据第一行、第一列标志位 置0
    for (let r = 1; r < rows; r++)
        for (let c = 1; c < cols; c++)
            if (matrix[r][0] == 0 || matrix[0][c] == 0)
                matrix[r][c] = 0;
    
    // 根据firstRowHasZero和firstColumnHasZero，是否置第一行、第一列为0
    if (firstRowHasZero)
        // 置第一行为0
        for (let c = 0; c < cols; c++)
            matrix[0][c] = 0;
    if (firstColumnHasZero)
        // 置第一列为0
        for (let r = 0; r < rows; r++)
            matrix[r][0] = 0;

};

// 参考题解（推荐）：https://leetcode-cn.com/problems/set-matrix-zeroes/solution/o1kong-jian-by-powcai/
