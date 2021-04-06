/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    // dp[i] 表示 s[i ... END] 一共有多少种解码方式
    let dp = [...Array(s.length + 1)].map(elem => 0);
    // dummy 位
    dp[dp.length-1] = 1;

    // base case
    if (parseInt(s[s.length-1]) >= 1 && parseInt(s[s.length-1]) <= 9) {
        dp[dp.length-2] = 1;
    } else {
        // "0" 无法单个解码，只「有可能」与其前面一位一起解码
        dp[dp.length-2] = 0;
    }

    for (let i = s.length-2; i >= 0; i--) {
        if (s[i] === "0")
            dp[i] = 0;
        else if (parseInt(s.slice(i, i+2)) >= 1 && parseInt(s.slice(i, i+2)) <= 26)
            dp[i] = dp[i+1] + dp[i+2];
        else
            dp[i] = dp[i+1];
    }

    // console.log(dp);

    return dp[0];

};

// 思路：从后往前计算解码方法，用一个一维数组记录 s 子串的解法方法个数
