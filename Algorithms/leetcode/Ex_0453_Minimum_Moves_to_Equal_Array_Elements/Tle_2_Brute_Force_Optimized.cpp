#include <vector>

using std::vector;

class Tle_2 {
public:
    int minMoves(vector<int>& nums) {
        int size = nums.size();
        int min = 0;            // 记录 nums 中最小数字的下标
        int max = size - 1;     // 记录 nums 中最大数字的下标
        int res = 0;    // 记录累加次数

        while (true) {
            // 寻找更新后的 nums 中最小／最大数字的下标
            for (int i = 0; i < size; i++) {
                if (nums[i] > nums[max]) {
                    // 如果当前下标的数字 大于 当前最大数字，更新最大数字的下标
                    max = i;
                }
                if (nums[i] < nums[min]) {
                    // 如果当前下标的数字 小于 当前最小数字，更新最小数字的下标
                    min = i;
                }
            }

            // 判断当前是否到达终止条件，即 最大数字 == 最小数字
            int K = nums[max] - nums[min];
            if (K == 0) {
                break;
            }

            // 除了最大数字的下标 max 之外，其他数字全部 + K
            // 优化点：与 Tle_1 相比，Tle_2 使得「nums中最小数字」追上「nums中最大数字」只需要一步，而 Tle_1 需要 diff 步
            for (int i = 0; i < size; i++) {
                if (i != max) {
                    nums[i] += K;
                }
            }

            res += K;
        }

        return res;
    }
};

// 参考题解：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/solution/zui-xiao-yi-dong-ci-shu-shi-shu-zu-yuan-su-xiang-d/
// 
// 设 N = nums.size()
// time complexity: O(N^2)
// space complexity: O(1)
