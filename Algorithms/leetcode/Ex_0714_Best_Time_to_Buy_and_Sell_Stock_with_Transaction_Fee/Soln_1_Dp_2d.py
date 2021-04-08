class Solution_1:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        if not prices or len(prices) == 0:
            return 0
        
        length = len(prices)

        dp = [[0 for _ in range(2)] for _ in range(length)]

        # base cases
        dp[0][0] = 0
        dp[0][1] = -prices[0] - fee     # 默认在买入的时候就扣除手续费

        for i in range(1, length):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
        
        return dp[length - 1][0]
        
