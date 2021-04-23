/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    // 这里定义时，最好规定数组长度
    // var dp = []
    const dp = [...Array(n+1)].map(_ => 0);
    // 基准可以与for循环合并
    // base cases
    // dp[0] = 0;     // 0
    // dp[1] = 1;     // 1
    // dp[2] = 2;     // 1 + 1
    // dp[3] = 3;     // 1 + 1 + 1
    for (let i = 1; i <= n; i++) {
        // let min = Number.MAX_SAFE_INTEGER;
        let min = i;    // 最坏情况每次都是 1
        for (let j = 1; i - j * j >= 0; j++) {
            min = Math.min(min, dp[i - j * j] + 1);
        }
        dp[i] = min;
    }
    return dp[n];
};

// 根据题解在我的提交上进行了优化：https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/
