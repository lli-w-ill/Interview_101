#include <vector>

using std::vector;
using std::max;

class Solution_3 {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int res = INT_MIN;
        // dp[i] 表示 nums[0 ... i-1] 的最大子序和
        vector<int> dp (size + 1, 0);
        // base case 1: nums[0 ... i-1] 为空
        dp[0] = 0;  // nums[0 ... -1] 之间最大子序和为 0
        // base case 2: 子数组最少包含一个元素，所以每个数字自形成一个子序列
        for (int i = 1; i <= size; i++) {
            dp[i] = nums[i-1];

            res = max(res, dp[i]);
        }

        // 开始填数组
        for (int i = 1; i <= size; i++) {
            // 状态转移方程
            // 情况一：将当前数字 (nums[i-1]) 累加到之前的最大连续子序和 (dp[i-1]) 上，形成更大的连续子序和  ->  dp[i-1] + nums[i-1]
            // 情况二：如果抛弃之前的最大子序和，而从当前数字重新开始一个新的子序列可以在 nums[0 ... i-1] 上得到更大的连续子序列和，那么就从当前数字开始重新计算子序列和  ->  dp[i]
            dp[i] = max(dp[i-1] + nums[i-1], dp[i]);

            res = max(res, dp[i]);
        }

        return res;
    }
};
