/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;

    var onBoard = (r, c) => {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (matrix[r][c] == 0) {
                for (let i = 0; i < cols; i++) {
                    if (matrix[r][i] != 0)
                        matrix[r][i] = '#'; // 整行置为#
                }
                for (let j = 0; j < rows; j++) {
                    if (matrix[j][c] != 0)
                        matrix[j][c] = '#'; // 整列置为#

                }
            }
        }
    }

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (matrix[r][c] == '#') {
                matrix[r][c] = 0;
            }
        }
    }
};

// 时间复杂度：O(rows * cols)
// 空间复杂度：O(1)
