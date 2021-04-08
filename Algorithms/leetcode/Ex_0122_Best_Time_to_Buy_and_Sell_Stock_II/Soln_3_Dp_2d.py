class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 0 or len(prices) == 1:
            return 0
        
        length = len(prices)

        # dp 是 length x 2 的二维数组
        # 第一维：第 i 天
        # 第二维：第 i 天是持有 0 份股票，还是持有 1 份股票
        # dp[i][0] 表示第 i 天不持有股票情况下的最大收益
        # dp[i][1] 表示第 i 天持有一份股票情况下的最大收益
        dp = [[0 for _ in range(2)] for _ in range(length)]

        # base cases
        dp[0][0] = 0
        dp[0][1] = -prices[0]

        for i in range(1, length):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])

        return dp[length-1][0]

# 参考文章（强烈推荐）：https://leetcode-cn.com/circle/article/qiAgHn/

