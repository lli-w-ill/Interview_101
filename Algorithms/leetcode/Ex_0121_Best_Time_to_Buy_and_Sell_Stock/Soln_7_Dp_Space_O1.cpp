#include <vector>

using std::vector;
using std::max;

class Solution_7 {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0;
        int buy = INT_MIN;

        for (int i = 0; i < prices.size(); i++) {
            buy = max(buy, -prices[i]);     // 计算 prices[0 ... i] 间最低的买入价格
            sell = max(sell, buy + prices[i]);  // 以 prices[0 ... i] 间最低价格买入，以 prices[i] 价格卖出，更新最大利润 
        }

        return sell;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
