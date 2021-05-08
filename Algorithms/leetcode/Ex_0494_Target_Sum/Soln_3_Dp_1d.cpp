#include <vector>
#include <cstdlib>  // std::abs

using std::vector;
using std::abs;

class Solution_3 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // 计算nums中所有元素的sum ———— 用于计算 dp 的列数
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        // 特判
        if (abs(S) > abs(sum)) {
            return 0;
        }
        int size = nums.size();
        int colSize = 2 * sum + 1;

        // 初始化两个一维数组
        vector<int> pre (colSize, 0);   
        vector<int> cur (colSize, 0);
        if (nums[0] == 0) {
            // 初始时，pre相当与 2D-dp解法中的第一行，即i=0
            // nums[0 ... 0] 加或减 nums[0] 都的0
            // 列坐标为什么是 sum 而不是 0，是因为列坐标 0~sum-1 是留给「组合和」为负数的，列坐标sum是留给「组合和」为0的，列坐标 sum+1~2*sum 是留给「组合和」为正数的
            pre[sum] = 2;
        } else {
            pre[sum + nums[0]] = 1; // + nums[0]
            pre[sum - nums[0]] = 1; // - nums[0]
        }

        // 开始逐行向下滚动更新 pre 和 cur
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < colSize; j++) {
                // 状态转移方程：dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j-(-nums[i])] （在1d这里，只看纵坐标即可）
                int left = (j - nums[i] >= 0) ? j - nums[i] : 0;
                int right = (j + nums[i] < colSize) ? j + nums[i] : 0;
                cur[j] = pre[left] + pre[right];
            }
            // 将cur赋给pre，清空cur准备存储下一行的值，窗口下移
            pre.swap(cur);
            cur.clear();
        }
        return pre[sum + S];
    }
};

// 参考题解：https://leetcode-cn.com/problems/target-sum/solution/dong-tai-gui-hua-si-kao-quan-guo-cheng-by-keepal/
// 题解评论@szza：
// 根据 Soln_2 的 2D-Dp 解法中的状态转移方程，可知每次计算表格中行i的值，只需要直到其上一行行i-1的值就可以了，所以可以优化为使用两个一维数组，并滚动更新（像高度为2的滑动窗口一样往下滚动）
