/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    var squares = [];
    for (let i = Math.floor(Math.sqrt(n)); i >= 1; i--) {
        squares.push(i * i);
    }
    
    var queue = [0];
    var depth = 0;
    while (queue) {
        // 当前层的节点数
        var size = queue.length;
        for (let i = 0; i < size; i++) {
            var curSum = queue.shift();
            if (curSum === n) {
                return depth;
            }
            // 遍历 squares，将所有能与curSum累加后不超过n的数字与curSum累加，并将累加和加入到queue中
            for (let j = squares.length - 1; j >= 0 && curSum + squares[j] <= n; j--) {
                queue.push(curSum + squares[j]);
            }
        }
        depth += 1;
    }
};
