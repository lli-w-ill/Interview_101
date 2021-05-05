/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    // dp[i] 记录兑换 i 最少需要的硬币个数
    // 初始值为最大，最大值为全用1找零再加一张（尽管1可能不在coins中，但根据题目1是最小的coin）
    const dp = [...Array(amount+1)].map(_ => amount + 1);
    // 初始化 dp
    dp[0] = 0;
    for (let i = 0; i < coins.length; i++) {
        dp[coins[i]] = 1;
    }
    coins.sort((a, b) => {
        return a - b;   // 升序排序coins, 保证小的coins在前
    }); 
    // console.log(coins);

    // 开始dp循环
    var minCoin = Math.min(coins);
    for (let i = 1; i <= amount; i++) {
        for (let j = 0; j < coins.length; j++) {
            if (i < coins[j]) {
                // 说明找不开，直接break（因为小coins已经找不开了）
                break;
            } else {
                dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if (dp[amount] == amount + 1) {
        // 找不开
        return -1;
    } else {
        return dp[amount];
    }
};

// 配合Ex279.完全平方数 一起做
