class Solution_6:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 0:
            return 0
        
        length = len(prices)

        profit0 = 0             # 前一天（当前是第 1 天）不持有股票的情况下，最大收益为 0
        profit1 = -prices[0]    # 前一天持有一份股票的情况下（当前是在第 1 天购买股票），最大收益为 -prices[0] （第一天花掉的购买股票的钱）
        
        for i in range(1, length):
            # dp[i][0] ：第 i 天不持有股票时的最大收益
            # dp[i-1][0] -> 第 i-1 天不持有股票时的最大收益（即第 i 天进行休息操作）
            # dp[i-1][1] + prices[i] -> 第 i-1 天持有 1 份股票，并在第 i 天卖出
            # dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            profit0 = max(profit0, profit1 + prices[i])

            # dp[i][1]：第 i 天持有 1 份股票时的最大收益
            # dp[i-1][1] -> 第 i-1 天持有股票时的最大收益（即第 i 天进行休息操作）
            # -prices[i] -> 第 i-1 天不持有股票，并在第 i 天买入
            # dp[i][1] = max(dp[i-1][1], -prices[i])
            profit1 = max(profit1, -prices[i])
        
        # 最后一天结束时持有 0 份股票的收益一定大于持有 1 份股票的收益
        # return dp[length-1][0]
        return profit0

# 参考文章（强烈推荐）：https://leetcode-cn.com/circle/article/qiAgHn/
