/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if (n == 1) return '1';
    const regex = /(\d)\1*/g;
    const temp = countAndSay(n - 1).match(regex);
    let res = '';
    for (let i = 0; i < temp.length; i++) {
        res += (temp[i].length + '' + temp[i].substring(0, 1));
    }
    return res;
};
