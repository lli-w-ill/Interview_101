class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 0 or len(prices) == 1:
            return 0
        
        length = len(prices)
        maxK = (length + 1) // 2      # 最多能够执行「卖出交易」（下文交易均为「卖出交易」）的次数为 length/2 的上整

        # dp 是 length x maxK x 2 的三维数组
        # 第一维：第 i 天
        # 第二维：最多能够在进行 k 次交易
        # 第三维：第 i 天是持有 0 份股票，还是持有 1 份股票
        # dp[i][k][0] 表示第 i 天还能再交易 k 次，且不持有股票情况下的最大收益
        # dp[i][k][1] 表示第 i 天还能再交易 k 次，且持有一份股票情况下的最大收益
        dp = [[[0 for _ in range(2)] for _ in range(maxK)] for _ in range(length)]

        # base cases
        for k in range(maxK):
            dp[0][k][0] = 0
            dp[0][k][1] = -prices[0]

        for i in range(1, length):
            for k in range(maxK):
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
                
                if k - 1 >= 0:
                    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
                else:
                    dp[i][k][1] = dp[i-1][k][1]

        return max(dp[length-1][k][0] for k in range(maxK))

# 参考文章（强烈推荐）：https://leetcode-cn.com/circle/article/qiAgHn/

