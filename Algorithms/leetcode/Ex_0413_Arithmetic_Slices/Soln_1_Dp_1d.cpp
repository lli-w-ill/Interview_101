#include <vector>
#include <numeric>

using std::vector;
using std::accumulate;

class Solution_1 {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) {
            return 0;
        }

        // dp[i] 表示以 nums[i] 结尾的等差数组的个数
        vector<int> dp (size, 0);
        for (int i = 2; i < size; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = dp[i-1] + 1;
            }
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394

