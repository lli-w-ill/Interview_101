#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_1 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int size = prices.size();
        if (size == 1) {
            return 0;
        }

        // canBuy[i] 表示在第i天处于「可以买入」时（但还没买入时）的最大利润，因为 s0 可以来自于 s0 (上一天休息) 或 s2 (上一天休息)
        // canSell[i] 表示在第i天处于「可以卖出」时（但还没有卖出）的最大收益，因为 s1 可以来自与 s0 (上一天购买股票) 或 s1 (上一天休息)
        // cooldown[i] 表示在第i天处于「休息状态」时的最大利润，s2 可以来自 s1 (上一天买入股票)
        vector<int> canBuy (size, 0);       // s0: 如果处于当前状态，表示处于「可以买入」状态
        vector<int> canSell (size, 0);      // s1: 如果在当前状态，表示处于「可以卖出」状态
        vector<int> cooldown (size, 0);     // s2: 休息状态
        
        // set base case
        canBuy[0] = 0;              // 第一天休息，最大利润是0
        canSell[0] = -prices[0];    // 因为是「可以卖出」状态，所以必在第一天买入股票，所以第一天的最大利润是-prices[0]
        cooldown[0] = INT_MIN;      // 因为cooldown (s2) 只能来自 canSell (s1)，而第一天还没有股票，所以最大利润是负无穷

        // 开始 dp 循环
        for (int i = 1; i < size; i++) {
            // 更新在第i天处于「可以买入」时的最大利润（当前还没有股票 no-stock）
            //      buy[i-1]: last no-stock profit 
            //      cooldown[i-1]: last cooldown profit
            canBuy[i] = max(canBuy[i-1], cooldown[i-1]);            // 更新 s0
            // 更新在第i天处于『可以卖出』时的最大利润（当前有股票 with-stock）
            //      canSell[i-1]: last with-stock profit
            //      canBuy[i-1]-prices[i]: last no-stock profit but buy at day i
            canSell[i] = max(canSell[i-1], canBuy[i-1] - prices[i]);// 更新 s1
            // 更新在第i天处于『休息』状态的最大利润
            //     canSell[i-1] + prices[i]: sell the stock at day i and take a rest
            cooldown[i] = canSell[i-1] + prices[i];                 // 更新 s2
            
        }
        
        return max(canBuy[size-1], cooldown[size-1]);
    }
};

// 参考题解（强烈推荐）：https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
// 参考题解下@bumblecode的评论（强烈推荐）
//   (rest)
//     ←
//   ↙   ↖     (rest)
//  →→→→→s0 ← ← ← ← ← ← s2 
//         ↘           ↗
//    (buy)  ↘       ↗  (sell)
//             ↘   ↗
//              s1
//            ↙    ↖
//           →→→→→→→→
//            (rest)
// 注：括号内是action
// s0: 当前可以购买（且没有任何存留股票）
// s1: 当前可以卖出（之前有购买过的股票）
// s2: 当前处于休息状态
// 在状态图中s0, s1, s2表示当天的状态，而线段表示当天到下一天采取的行动
// 
//   (buy)(sell)(rest)(buy)(..)
//    ↗  ↘  ↗  ↘ ↗  ↘ ↗  ↘ ↗  ↘
//  -------------------------------
// | s0 | s1 | s2 | s0 | s1 | ...
//  -------------------------------
// 上图中每个方格表示 prices 中的价格的状态，而(...)表示当天采取的行动
//
