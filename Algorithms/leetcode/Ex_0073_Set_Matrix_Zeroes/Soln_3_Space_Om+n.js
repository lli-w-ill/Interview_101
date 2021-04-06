/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;

    let rows2Zero = new Set();
    let cols2Zero = new Set();

    // 扫第一遍
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (matrix[r][c] == 0) {
                rows2Zero.add(r);
                cols2Zero.add(c);
            }
        }
    }

    // 扫第二遍
    rows2Zero.forEach((r) => {
        for (let c = 0; c < cols; c++) {
            matrix[r][c] = 0;
        }
    })
    cols2Zero.forEach((c) => {
        for (let r = 0; r < rows; r++) {
            matrix[r][c] = 0;
        }
    })

};


// 思路：扫两遍，第一遍记录那些行／列需要被置 0，第二遍置 0
