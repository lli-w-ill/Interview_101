#include <vector>
#include <cstdlib>

using std::vector;
using std::abs;

class Solution_4 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();

        // 首先计算 sum
        int sum = 0;
        for (int &num : nums) {
            sum += num;
        }

        // 特判
        if (abs(S) > abs(sum)) {
            // 所有值的绝对值加起来都小于 S 得绝对值
            return 0;
        }

        // dp[i][j] 表示 nums[0...i] 内所有数字通过 +/- 凑成 j 的方法数
        //  1. dp[:][0 ... sum-1] 代表 nums 内「组合和」等于 -abs(j) 时的方法数
        //  2. dp[:][sum] 代表 nums 内「组合和」等于 0 时的方法数
        //  3. dp[:][sum+1 ... 2*sum] 代表 nums 内「组合和」等于 +abs(j) 时的方法数
        vector<vector<int>> dp (size, vector<int> (2 * sum + 1, 0));

        // base cases
        dp[0][0] = 0;
        if (nums[0] == 0) {
            // 因为第一个数凑成 0 有两种方法：+0，-0
            dp[0][sum + nums[0]] += 1;
            dp[0][sum - nums[0]] += 1;
        } else {
            dp[0][sum + nums[0]] += 1;   // +nums[0]
            dp[0][sum - nums[0]] += 1;   // -nums[0]
        }

        for (int i = 1; i < size; i++) {
            int num = nums[i];
            
            for (int j = 0; j < 2 * sum + 1; j++) {
                
                // 减去 nums[i]
                int left = 0;
                if (j - num >= 0) {
                    left = dp[i-1][j-num];
                }

                // 加上 nums[i]
                int right = 0;
                if (j + num < 2 * sum + 1) {
                    right = dp[i-1][j+num];
                }

                dp[i][j] = left + right;
            }
        }

        return dp[size - 1][sum + S];

    }
};

// 参考题解：https://leetcode-cn.com/problems/target-sum/solution/dong-tai-gui-hua-si-kao-quan-guo-cheng-by-keepal/
