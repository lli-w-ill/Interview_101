#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int len = prices.size();
        if (len == 0 || len == 1) {
            return res;
        }
        stack<int> st;
        int buyPrice;
        // 添加哨兵
        prices.push_back(-1);
        // 开始扫描
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && st.top() >= prices[i]) {
                // 弹栈，直到栈空或者栈顶元素值 小于 当前元素值，并且弹栈过程中与栈底元素计算差值，更新最大收益
                res = max(st.top() - buyPrice, res);
                st.pop();
            }
            if (st.empty()) {
                // 更新买入价格，即栈底元素的值
                buyPrice = prices[i];
            }
            st.push(prices[i]);
        }
        return res;
    }
};

// 题解参考（强烈推荐）：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/
// 单调栈思路：
// 1. 数组prices最后添加哨兵，以保证最后时依次弹出栈内所有值，并计算差值、检查更新最大收益值
// 2. 如果栈空或者当前扫描到的元素 > 栈顶元素的值，则入栈
// 3. 如果当前扫描的元素 <= 栈顶元素的值，则循环弹栈，直到栈空或者栈顶元素 > 当前元素，然后将当前元素进栈
//    并且每次弹栈时，计算栈顶元素与栈底元素（即买入价格）的差，检查是否需要更新最大收益值
// 注：循环不变量：栈底元素即为买入的价格，栈顶元素为当前扫过的最大价格
