package Algorithms.leetcode.Ex_121_Best_Time_to_Buy_and_Sell_Stock;

class Solution_2 {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;   // 记录从0到当前下标所找到的最小价格
        int res = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minPrice) {
                // 随着往后扫，更新最小价格
                minPrice = prices[i];
            } else if (prices[i] - minPrice > res) {
                // 如果当前价格与 prices[0...i-1] 的最小价格之间价差 > 之前的最大利润，则更新res
                res = prices[i] - minPrice;
            }
        }
        return res;
    }
}

// 解法参考：https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/

