#include <vector>

using std::vector;

class Solution_5 {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size <= 1) {
            return 0;
        }

        int profit = 0;
        for (int i = 1; i < size; i++) {
            if (prices[i] > prices[i-1]) {
                // 如果昨天价格比今天低，那么就昨天买入，今天卖出
                // （有种站在未来 [相对于过去的未来] 的视角，根据过去的信息，来判断当前 [这里的当前等于前面的未来] 的抉择的感觉）
                profit += (prices[i] - prices[i-1]);
            }
        }
        
        return profit;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
