/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    const map = {
        "I": 1,
        "IV": 4,
        "IX": 9,
        "V": 5,
        "X": 10,
        "XL": 40,
        "XC": 90,
        "L": 50,
        "C": 100,
        "CD": 400,
        "CM": 900,
        "D": 500,
        "M": 1000
    }

    let res = 0;
    for (let i = 0; i < s.length;) {
        if (i + 1 < s.length && map[s.substring(i, i + 2)]) {
            res += map[s.substring(i, i + 2)];
            i += 2;
        } else {
            res += map[s[i]];
            i += 1;
        }
    }

    return res;
};

// 参考题解：https://leetcode-cn.com/problems/roman-to-integer/solution/hua-jie-suan-fa-13-luo-ma-shu-zi-zhuan-zheng-shu-b/