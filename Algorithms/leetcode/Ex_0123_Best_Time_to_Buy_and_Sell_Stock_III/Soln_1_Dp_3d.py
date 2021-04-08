class Solution_1:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 0:
            return 0
        
        length = len(prices)
        # dp 是 length x 3 x 2 的三维数组
        # 第一维：第 i 天
        # 第二维：最多能够再进行 k 笔「卖出交易」（以下交易均指卖出交易）
        # 第三维：当前天是持有 0 份股票，还是持有 1 份股票
        dp = [[[0 for _ in range(2)] for _ in range(3)] for _ in range(length)]

        # base cases
        dp[0][0][0] = 0
        dp[0][1][0] = 0
        dp[0][2][0] = 0
        dp[0][0][1] = 0
        dp[0][1][1] = -prices[0]    # 第一天购买股票
        dp[0][2][1] = -prices[0]    # 第一天购买股票

        for i in range(1, length):
            # 第 i 天不持有股票，还剩 2 次交易次数的最大收益
            dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
            # 第 i 天持有股票，还剩 2 次交易次数的最大收益
            dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
            # 第 i 天不持有股票，还剩 1 次交易次数的最大收益
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
            # 第 i 天持有股票，还剩 1 次的交易次数的最大收益
            dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i])

        return max(dp[length-1][k][0] for k in range(3))

# 参考文章：https://leetcode-cn.com/circle/article/qiAgHn/
# 建议与 Ex121, Ex122 一起做效果更佳

