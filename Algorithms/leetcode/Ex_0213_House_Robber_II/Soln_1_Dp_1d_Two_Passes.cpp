#include <vector>

using std::vector;
using std::max;
using std::fill;

class Solution_1 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int size = nums.size();

        // dp[i] 表示在抢第 i-1 个房子（从第0个房子开始算）时（还没抢第 i-1 个房子）的最大利润
        vector<int> dp (size + 1, 0);
        // robbed[i] 表示是否抢了第 i 个房子（从第0个房子开始算）
        vector<int> robbed (size, false);

        int res = 0;
        // 第一轮：抢第 0 个房子
        dp[1] = nums[0];
        robbed[0] = true;
        for (int i = 2; i <= size; i++) {
            if (dp[i-1] < nums[i-1] + dp[i-2] && robbed[(i-1+1) % size] == false) {
                // 抢第 i-1 个房子
                dp[i] = nums[i-1] + dp[i-2];
                robbed[i-1] = true;
            } else {
                // 不抢第 i-1 个房子
                dp[i] = dp[i-1];
            }
        }

        // 打印 dp 结果
        // for (int i = 0; i < dp.size(); i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;

        res = max(res, dp[size]);

        // 第二轮：不抢第 0 个房子
        // 先重置 dp, robbed
        fill(dp.begin(), dp.end(), 0);
        fill(robbed.begin(), robbed.end(), false);
        dp[1] = 0;
        for (int i = 2; i <= size; i++) {
            if (dp[i-1] < nums[i-1] + dp[i-2] && robbed[(i-1+1) % size] == false) {
                // 抢第 i-1 个房子
                dp[i] = nums[i-1] + dp[i-2];
                robbed[i-1] = true;
            } else {
                // 不抢第 i-1 个房子
                dp[i] = dp[i-1];
            }
        }

        // 打印 dp 结果
        // for (int i = 0; i < dp.size(); i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;

        res = max(res, dp[size]);

        return res;

    }
};
