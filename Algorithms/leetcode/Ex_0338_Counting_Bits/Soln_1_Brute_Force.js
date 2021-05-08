/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    var res = []
    for (let i = 0; i <= num; i++) {
        var j = i;
        var count = 0;
        while (j > 0) {
            if (j & 1 == 1) {
                count += 1;
            }
            j >>= 1;
        }
        res.push(count);
    }
    return res;
};
