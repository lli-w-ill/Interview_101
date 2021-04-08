class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 0:
            return 0
        
        length = len(prices)
        dp = [[0 for _ in range(2)] for _ in range(length)]

        # base cases
        # dp[0][0] = 0    # 第一天不持有股票的最大收益
        prevProfit0 = 0
        profit0 = 0
        # dp[0][1] = -prices[0]   # 第一天持有股票的最大收益
        profit1 = -prices[0]

        for i in range(1, length):
            # dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            newProfit0 = max(profit0, profit1 + prices[i])

            # dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
            newProfit1 = max(profit1, prevProfit0 - prices[i])

            prevProfit0 = profit0
            profit0 = newProfit0
            profit1 = newProfit1

        # return dp[length - 1][0]
        return profit0


# 参考文章（强烈推荐）：https://leetcode-cn.com/circle/article/qiAgHn/
# 与 Ex121, Ex122, Ex123, Ex188 一起做更好
# 对比这个解法与 Ex122 Soln_3_Dp_2d 解法
# 本题状态转移方程：
# T[i][k][0] = max(T[i - 1][k][0], T[i - 1][k][1] + prices[i])
# T[i][k][1] = max(T[i - 1][k][1], T[i - 2][k][0] - prices[i])
# 
# 122题状态转移方程：
# T[i][k][0] = max(T[i - 1][k][0], T[i - 1][k][1] + prices[i])
# T[i][k][1] = max(T[i - 1][k][1], T[i - 1][k][0] - prices[i])
