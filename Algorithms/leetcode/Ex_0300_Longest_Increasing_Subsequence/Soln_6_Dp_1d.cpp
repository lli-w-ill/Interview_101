#include <vector>

using std::vector;
using std::max;

class Solution_6 {
public:
    int lengthOfLIS(vector<int>& nums) {    
        int size = nums.size();
        int res = 0;    // 记录最长递增子序列的长度
        
        // dp[i] 表示以 nums[i] 结尾的 LIS 的长度
        // 初始值均为 1，因为每个数字自身构成一个子序列
        vector<int> dp (size, 1);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            // 更新最长 LIS 的长度
            res = max(res, dp[i]);
        }

        return res;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 设 N = nums.size()
// time complexity: O(N^2)
// space complexity: O(N)

