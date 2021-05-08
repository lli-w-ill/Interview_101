#include <vector>

using std::vector;
using std::max;

class Solution_4 {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int cur = nums[0];
        int res = cur;

        for (int i = 1; i < size; i++) {
            // 状态转移方程
            // 情况一：将当前数字 (nums[i]) 累加到之前的最大连续子序和 (更新前的cur) 上，形成更大的连续子序和  ->  cur + nums[i]
            // 情况二：如果抛弃之前的最大子序和，而从当前数字重新开始一个新的子序列可以在 nums[0 ... i] 上得到更大的连续子序列和，那么就从当前数字开始重新计算子序列和  ->  nums[i]
            cur = max(cur + nums[i], nums[i]);

            res = max(res, cur);
        }

        return res;
    }
};

// 思路：由于 Soln_3_Dp_1d 中状态转移方程：dp[i] = max(dp[i-1] + nums[i-1], dp[i]) 只与 dp[i-1] 相关，所以可以用「滚动数组」（即双变量法）来压缩空间
