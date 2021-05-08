#include <vector>

using std::vector;
using std::max;

class Solution_3 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        // 特判1: 只有 0 或 1 天
        if (days < 2) {
            return 0;
        }
        // 特判2: k >= days，可以在任意一天随便买卖
        if (k >= days) {
            return maxProfitUnlimited(prices);
        }

        // buy[j] 表示在第 j 次买入时的最大收益
        // sell[j] 表示在第 j 次卖出时的最大收益
        vector<int> buy (k + 1, INT_MIN);
        vector<int> sell (k + 1, 0);

        for (int i = 0; i < days; i++) {
            for (int j = 1; j <= k; j++) {
                // 注意：需要先更新 buy[j]，再更新 sell[j]

                // 更新如果在第 i 天第 j 次买入时的最大收益
                buy[j] = max(buy[j], sell[j-1] + (-prices[i]));
                
                // 更新如果在第 i 天第 j 次卖出时的最大收益
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }

        return sell[k];
    }

private:
    // 等同于 Ex.122 解法
    int maxProfitUnlimited(vector<int> &prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i+1] > prices[i]) {
                maxProfit = maxProfit + (prices[i+1] - prices[i]);
            }
        }
        return maxProfit;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
