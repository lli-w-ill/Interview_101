#include <vector>

using std::vector;

class Solution_2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        // 降序排序coins，先拿大币找
        sort(coins.rbegin(), coins.rend());
        int res = INT_MAX;
        coinChange(coins, amount, 0, 0, res);
        return res == INT_MAX ? -1 : res;
    }

private:
    void coinChange(vector<int> &coins, int amount, int index, int coinCnt, int &res) {
        if (amount == 0) {
            // 找到一种方案
            // res = min(res, coinCnt); // 其实这里不用取 min 的，因为下面for循环终止条件已经限制了
            res = coinCnt; 
            return;
        }
        if (index == coins.size()) {
            // 所有币都找不开
            return;
        }
        // 从大币开始找零，且大币从顶到头的数量开始找（推荐题解中的插图）
        for (int k = amount / coins[index]; k >= 0 && k + coinCnt < res; k--) {
            coinChange(coins, amount - coins[index] * k, index + 1, coinCnt + k, res);
        }
    }
};

// 参考题解：https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/
