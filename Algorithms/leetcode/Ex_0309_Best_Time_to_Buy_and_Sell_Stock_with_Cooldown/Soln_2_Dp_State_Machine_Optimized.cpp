#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_2 {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;           // 卖出状态时的最大利润
        int hold = INT_MIN;     // 持有状态时的最大利润
        int rest = 0;            // 买入状态时的最大利润
        for (int i = 0; i < prices.size(); i++) {
            int prevSold = sold;
            // 更新卖出状态的最大利润
            sold = hold + prices[i];    // 在第i天卖出
            // 更新持有状态时的最大利润
            //         hold: 上次持有时的最大利润
            //               rest - prices[i]: 在第i-1天休息状态的最大利润 并 在第i天买入股票 
            hold = max(hold, rest - prices[i]);    
            // 更新休息状态的最大利润 
            //         rest: 上一次休息状态的最大利润
            //               prevSold: 上一次卖出时的最大利润
            rest = max(rest, prevSold);
        }
        return max(sold, rest);
    }
};

// 参考题解（强烈推荐）：https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
// 参考题解下热评第一@Halet评论
//
