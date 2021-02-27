/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    let res = 0;
    let len = s.length;
    const dp = new Array(len);
    for (let i = 0; i < len; i++) {
        // 初始化为 false
        dp[i] = new Array(len).fill(false);
    }

    for (let end = 0; end < len; end++) {
        for (let start = 0; start <= len; start++) {
            if (start === end) {
                // 单个字符一定是回文子串
                dp[start][end] = true;
                res += 1;
            } else if (end - start === 1 && s[start] === s[end]) {
                // 长度为2的回文子串
                dp[start][end] = true;
                res += 1;
            } else if (end - start > 1 && s[start] === s[end] && dp[start+1][end-1] === true) {
                // 长度大于1的回文子串
                dp[start][end] = true;
                res += 1;
            }
        }
    }
    return res;
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/palindromic-substrings/solution/shou-hua-tu-jie-dong-tai-gui-hua-si-lu-by-hyj8/

