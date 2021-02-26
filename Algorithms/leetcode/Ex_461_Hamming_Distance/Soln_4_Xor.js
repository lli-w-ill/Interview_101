/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    var res = 0;
    var xor = x ^ y;
    while (xor) {
        if (xor & 1) {
            res += 1;
        }
        xor >>= 1;
    }
    return res;
};
