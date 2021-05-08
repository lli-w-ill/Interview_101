#include <vector>

using std::vector;
using std::max;

class Solution_6 {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        // 特判
        if (size == 0) {
            return 0;
        }

        // 建立四个状态数组，记录每一天时不同状态下的利润
        vector<int> buy (size);     // 买入状态
        vector<int> sell (size);    // 卖出状态
        vector<int> s1 (size);      // 买入后等待卖出状态
        vector<int> s2 (size);      // 卖出后 cooldown 或卖出后等待状态

        // base case 1: 如果在第一天买入股票
        buy[0] = -prices[0];
        s1[0] = -prices[0];
        // base case 2: 第一天不可能卖出股票
        sell[0] = 0;
        s2[0] = 0;

        // 从第二天开始循环
        for (int i = 1; i < size; i++) {
            // 注意更新状态数组的顺序（按照base case的顺序）

            buy[i] = s2[i-1] + (-prices[i]);
            s1[i] = max(buy[i-1], s1[i-1]);
            sell[i] = max(buy[i-1] + prices[i], s1[i-1] + prices[i]);
            s2[i] = max(s2[i-1], sell[i-1]);
        }

        // 最后只有可能是「卖出股票时的最后一个状态」或者「卖出后等待买入时的最后一个状态」可能达到最多的利润
        return max(sell[size-1], s2[size-1]);

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
