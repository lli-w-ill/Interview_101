/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;

    // deep copy
    let res = [];
    for (let i = 0; i < rows; i++) {
        res.push(matrix[i].map(elem => elem));
    }

    // console.log(res);

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (matrix[r][c] == 0) {
                for (let i = 0; i < cols; i++) {
                    res[r][i] = 0; // 整行置为#
                }
                for (let j = 0; j < rows; j++) {
                    res[j][c] = 0; // 整列置为#

                }
            }
        }
    }

    // console.log(res);

    // shallow copy
    for (let i = 0; i < rows; i++) {
        matrix[i] = res[i];
    }
};

// 思路：拷贝一份 matrix，在原 matrix 上查找 0，在拷贝份上置 0
// deep copy js参考：https://medium.com/@ziyoshams/deep-copying-javascript-arrays-4d5fc45a6e3e
