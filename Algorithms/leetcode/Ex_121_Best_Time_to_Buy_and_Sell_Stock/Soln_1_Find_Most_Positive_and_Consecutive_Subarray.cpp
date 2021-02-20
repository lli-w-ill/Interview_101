#include <vector>

using std::vector;

class Solution_1 {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int len = prices.size();
        if (len == 0 || len == 1) {
            return res;
        }
        // 首先计算每相邻两天的价格差
        vector<int> diff;
        for (int i = 0; i < len - 1; i++) {
            diff.push_back(prices[i+1] - prices[i]);
        }
        // 从前往后扫描 diff，找到能达到最大值的连续子串
        int curProfit = 0;
        for (int i = 0; i < diff.size(); i++) {
            curProfit += diff[i];
            if (curProfit > res) {
                // 更新最大profit
                res = curProfit;
            }
            if (curProfit <= 0) {
                // 如果一个连续子串的累计profit等于0了，就从下一天从0新开始累计
                curProfit = 0;
            }
        }
        return res;
    }
};

// 想法：先计算每相邻两天的利润（或负利润），保存到diff中，然后在 diff 中从0开始往后找一个连续的子串，且该子串中的元素和达到最大。
// 如果中途子串元素和为 0 或者小于 0 了，说明从 0 到当前位置是不赚钱或者亏的，那么从下一个位置重新开始计算利润。
