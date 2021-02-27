/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    // 初始化 dp 二维数组
    // dp[i][j] 表示 s[i...j] 是否是回文子串
    var dp = new Array(s.length);
    var i;
    for (i = 0; i < s.length; i++) {
        dp[i] = new Array(s.length);
    }
    var rows = s.length;
    var cols = s.lengthl
    // 初始化2d数组为false
    Array.from({length: rows}, () => Array(cols).fill(false));
    // 初始化长度为1，和长度为2的回文子串
    var res = 0;
    for (i = 0; i < s.length; i++) {
        // 每个单词自身都是回文子串
        dp[i][i] = true;
        res += 1;
    }
    for (i = 0; i < s.length - 1; i++) {
        // 判断s[i ... i+1]是否是回文子串
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            res += 1;
        }
    }

    // 填表
    var len, start; 
    for (len = 3; len <= s.length; len++) {
        for (start = 0; start <= s.length - len; start++) {
            // 判断 s[start ... s+len-1] 是不是回文子串
            var end = start + len - 1;
            if (dp[start+1][end-1] === true && s[start] === s[end]) {
                dp[start][end] = true;
                res += 1;
            }
        }
    }
    return res;
};

// js初始化二维数组：https://stackoverflow.com/questions/3689903/how-to-create-a-2d-array-of-zeroes-in-javascript
// 这道题配合「Ex5.最长回文子串一起做」效果更佳
