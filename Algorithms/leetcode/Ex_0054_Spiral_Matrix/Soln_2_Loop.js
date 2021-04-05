/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
class ObjectSet extends Set {
    add(elem) {
        return super.add(typeof elem === 'object' ? JSON.stringify(elem) : elem);
    }

    has(elem) {
        return super.has(typeof elem === 'object' ? JSON.stringify(elem) : elem);
    }
}

var spiralOrder = function(matrix) {
    if (matrix.length == 0)
        return []

    const rows = matrix.length;
    const cols = matrix[0].length;

    let visited = new ObjectSet();
    let r = 0;
    let c = 0;
    let res = [];    

    while (r >= 0 && r < rows && c >= 0 && c < cols && !visited.has([r, c])) {  // 需要加上 c >= 0 以防matrix只有一个元素
        // 向右
        while (c < cols && !visited.has([r, c])) {
            res.push(matrix[r][c]);
            visited.add([r, c]);
            if ((c + 1 >= cols) || (c + 1 < cols && visited.has([r, c + 1]))) {
                break;
            }
            c += 1;
        }
        r += 1;     // 向下移动一格
        // console.log("向右", r, c);

        // 向下
        while (r < rows && !visited.has([r, c])) {
            res.push(matrix[r][c]);
            visited.add([r, c]);
            if ((r + 1 >= rows) || (r + 1 < rows && visited.has([r + 1, c]))) {
                break;
            }
            r += 1;
        }
        c -= 1      // 向左移动一格
        // console.log("向下", r, c);

        // 向左
        while (c >= 0 && r < rows && !visited.has([r, c])) {    // 需要加上 r < rows 以防matrix只有一行元素
            res.push(matrix[r][c]);
            visited.add([r, c]);
            if ((c - 1 < 0) || (c - 1 >= 0 && visited.has([r, c - 1]))) {
                break;
            }
            c -= 1;
        }
        r -= 1;     // 向上移动一格
        // console.log("向左", r, c);

        // 向上
        while (r >= 0 && c >= 0 && !visited.has([r, c])) {
            res.push(matrix[r][c]);
            visited.add([r, c]);
            if (((r - 1 < 0) || (r - 1 >= 0 && visited.has([r - 1, c])))) {
                break;
            }
            r -= 1;
        }
        c += 1;     // 向右移动一格
        // console.log("向上", r, c);

    }

    return res;
};

// 参考 javascript set of tuples: https://stackoverflow.com/questions/63179867/set-of-tuples-in-javascript
