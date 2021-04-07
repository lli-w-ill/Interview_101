class Solution_4:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) == 0:
            return 0
        
        length = len(prices)
        
        # dp 是 length x 2 x 2 的三维数组
        # 第一维：第 i 天
        # 第二维：最多能够再进行「卖出交易」的次数 k (本题因为只允许一次卖出交易，所以 k = 0 / 1)（下文注释中「交易」均指「卖出交易」）
        # 第三维：在当天是持有 0 份股票，还是持有 1 份股票
        # dp[i][k][0] 表示第 i 天还能再交易 k 次，且不持有股票情况下的最大收益
        # dp[i][k][1] 表示第 i 天还能再交易 k 次，且持有一份股票情况下的最大收益
        dp = [[[0 for _ in range(2)] for _ in range(2)] for _ in range(length)]

        # base cases
        dp[0][0][0] = 0     # 第 1 天没法再交易，且当前不持有股票的情况下，最大收益为 0
        dp[0][1][0] = 0     # 第 1 天可以再交易 1 次，且当前不持有股票的情况下，最大收益为 0
        dp[0][0][1] = float('-inf')    # 第 1 天没法再交易，且当前持有一份股票的情况下的最大收益（这种情况不可能，因为第一天刚买了股票，肯定还剩 1 次可以交易的机会）
        dp[0][1][1] = -prices[0]    # 第 1 天可以再交易 1 次，且当前持有一份股票的情况下（只能是在第一天购买股票），最大收益为 -prices[0] （第一天花掉的购买股票的钱）
        
        for i in range(1, length):
            # dp[i][1][0] ：第 i 天不持有股票时的最大收益
            # dp[i-1][1][0] -> 第 i-1 天不持有股票时的最大收益（即第 i 天进行休息操作）
            # dp[i-1][1][1] + prices[i] -> 第 i-1 天持有 1 份股票，并在第 i 天卖出
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])

            # dp[i][1][1]：第 i 天持有 1 份股票时的最大收益
            # dp[i-1][1][1] -> 第 i-1 天持有股票时的最大收益（即第 i 天进行休息操作）
            # dp[i-1][0][0] - prices[i] -> 第 i-1 天不持有股票，并在第 i 天买入
            dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i])

            # dp[i][0][0] 和 dp[i][0][1] 都是 base case，不用计算
        
        # 最后一天结束时持有 0 份股票的收益一定大于持有 1 份股票的收益
        # 所以第三维一定是 0
        return max(dp[length-1][1][0], dp[length-1][0][0])

# 参考文章（强烈推荐）：https://leetcode-cn.com/circle/article/qiAgHn/

