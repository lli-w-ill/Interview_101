#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution_4 {
public:
    int lengthOfLIS(vector<int>& nums) {    
        // 特判
        if (nums.size() == 0) {
            return 0;
        }
        
        // dp[i] represent the length of the LIS considering the element nums[0 ... i] by necessarily including nums[i]  
        // in order to find out dp[i], we need to append nums[i] in every possible increasing subsequence upto nums[i-1] such that new subsequence is also increasing.
        // 状态转移方程：
        // dp[i] = max(dp[j]) + 1, ∀ 0 ≤ j < i and num[i] > num[j] 
        // 最终所求： 
        // max(dp[i]),∀ 0 ≤ i < n
        vector<int> dp (nums.size(), 0);
        dp[0] = 1;  // nums[0] 自身是一个长度为1的 LIS
        int res = 1;
        
        // 开始填 dp 表
        for (int i = 1; i < dp.size(); i++) {
            // 找到 nums[0 ... i-1] 中最长的 LIS 的长度，且在这个最长的 LIS 尾部插入 nums[i] 依旧保证递增
            int preMaxDp = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    preMaxDp = max(preMaxDp, dp[j]);
                }
            }
            dp[i] = preMaxDp + 1;
            res = max(res, dp[i]);
        }

        return res;
    }
};

// 参考题解（非常推荐）：https://leetcode.com/problems/longest-increasing-subsequence/solution/

