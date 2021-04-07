class Solution_5:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 0:
            return 0
        
        length = len(prices)
        
        # dp 是 length x 2 的二维数组
        # 第一维：第 i 天
        # 第二维：在当天是持有 0 份股票，还是持有 1 份股票（Dp_3d 解法中的第三维）
        # dp[i][0] 表示第 i 天不持有股票情况下的最大收益
        # dp[i][1] 表示第 i 天持有一份股票情况下的最大收益
        dp = [[0 for _ in range(2)]  for _ in range(length)]

        # base cases
        dp[0][0] = 0            # 第 1 天不持有股票的情况下，最大收益为 0
        dp[0][1] = -prices[0]   # 第 1 天持有一份股票的情况下（只能是在第一天购买股票），最大收益为 -prices[0] （第一天花掉的购买股票的钱）
        
        for i in range(1, length):
            # dp[i][0] ：第 i 天不持有股票时的最大收益
            # dp[i-1][0] -> 第 i-1 天不持有股票时的最大收益（即第 i 天进行休息操作）
            # dp[i-1][1] + prices[i] -> 第 i-1 天持有 1 份股票，并在第 i 天卖出
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])

            # dp[i][1]：第 i 天持有 1 份股票时的最大收益
            # dp[i-1][1] -> 第 i-1 天持有股票时的最大收益（即第 i 天进行休息操作）
            # -prices[i] -> 第 i-1 天不持有股票，并在第 i 天买入
            dp[i][1] = max(dp[i-1][1], -prices[i])
        
        # 最后一天结束时持有 0 份股票的收益一定大于持有 1 份股票的收益
        return dp[length-1][0]

# 参考文章（强烈推荐）：https://leetcode-cn.com/circle/article/qiAgHn/

