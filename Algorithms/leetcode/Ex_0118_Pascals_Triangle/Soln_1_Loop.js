/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    if (numRows == 1)
        return [[1]];
    if (numRows == 2)
        return [[1], [1,1]];
    
    res = [[1], [1,1]];
    for (let r = 2; r < numRows; r++) {
        // 获取上一行
        let preRow = res[r-1];

        // 初始化行 r
        let curr = [...Array(preRow.length + 1)].map(elem => 1);
    
        // 根据上一行计算 curr[1 ... curr.length-2] 之间的数字
        for (let i = 1; i <= curr.length - 2; i++) {
            curr[i] = preRow[i-1] + preRow[i];
        }

        res.push(curr);
    }

    return res;
};
