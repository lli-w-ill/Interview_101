class Solution_2:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices or len(prices) == 0:
            return 0
        
        length = len(prices)
        if k >= length // 2:
            return self.maxProfit122(prices)
        
        return self.maxProfit188(k, prices)

    def maxProfit188(self, k: int, prices: List[int]) -> int:
        length = len(prices)

        # dp = [[[0 for _ in range(2)] for _ in range(k + 1)] for _ in range(length)]
        dp = [[0 for _ in range(2)] for _ in range(k + 1)]

        # base cases
        # for i in range(k + 1):
        #     dp[0][i][0] = 0
        #     dp[0][i][1] = -prices[0]
        for i in range(k + 1):
            dp[i][0] = 0
            dp[i][1] = -prices[0]

        for i in range(1, length):
            for j in range(k, 0, -1):
                # dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
                # dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i])
                dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i])

        # return dp[length-1][k][0]
        return dp[k][0]

    def maxProfit122(self, prices: List[int]) -> int:
        length = len(prices)

        dp = [[0 for _ in range(2)] for _ in range(length)]

        # base case
        # dp[0][0] = 0            # 第一天不持有股票的最大收益
        profit0 = 0
        # dp[0][1] = -prices[0]   # 第一天持有股票的最大收益
        profit1 = -prices[0]

        for i in range(1, length):
            # dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            # dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
            newProfit0 = max(profit0, profit1 + prices[i])
            newProfit1 = max(profit1, profit0 - prices[i])
            profit0 = newProfit0
            profit1 = newProfit1

        # return dp[length-1][0]
        return profit0


# 参考文章（强烈推荐）：https://leetcode-cn.com/circle/article/qiAgHn/
# 建议与 Ex121, Ex122, Ex123 一起做
