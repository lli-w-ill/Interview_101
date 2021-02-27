/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    let res = 0;
    let len = s.length;
    const dp = new Array(len).fill(false);
    for (let end = 0; end < len; end++) {
        for (let start = 0; start <= end; start++) {
            if (start == end) {
                dp[start] = true;
                res += 1;
            } else if (end - start == 1 && s[start] == s[end]) {
                dp[start] = true;   // 标志记在起始位置
                res += 1;
            } else if (end - start > 1 && s[start] == s[end] && dp[start + 1] == true) {
                dp[start] = true;   // 标志记在起始位置
                res += 1;
            } else {
                // 这个else分支是必要的，因为以 s = "fdsklf" 为例，当 start == end == 1 是，它们都指向'd'，这时 s[start] = true，但是当 end = 2, start = 1 时，s[start...end] = "ds" 不是回文子串，所以此时需要将 dp[start] 置false，否则会影响判断当 end = len - 1, start = 0 时的判断 ———— end - start = len - 1 > 0 && s[start] == s[end] == 'f' && dp[start+1] = true (dp[start+1]=true是错误的，因为"dskl"不是回文子串)
                dp[start] = false;
            }
        }
    }
    return res;
};

// 参考题解（非常推荐）：https://leetcode-cn.com/problems/palindromic-substrings/solution/shou-hua-tu-jie-dong-tai-gui-hua-si-lu-by-hyj8/
