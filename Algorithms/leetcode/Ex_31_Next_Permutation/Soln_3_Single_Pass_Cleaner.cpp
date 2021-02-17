#include <vector>

using std::vector;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return;
        }
        int i = len - 2;
        int j = len - 1;
        int k = len - 1;
        // 从后向前，寻找第一个相邻升序
        while (i >= 0 && nums[i] >= nums[j]) {
            i -= 1;
            j -= 1;
        }
        if (i >= 0) {
            // 不是最后一个序列
            // 从后向前，找到第一个刚刚大于nums[i]的『大数』
            while (k > i && nums[k] <= nums[i]) {
                k -= 1;
            }
            // 交换
            swap(nums, i, k);
        }
        // 此时nums[j ... len-1]应该还是逆序，将nums[j ... len-1]置为升序，因为升序是最小的排列
        k = len - 1;
        while (j < k) {
            swap(nums, j, k);
            j += 1;
            k -= 1;
        }
    }

private:
    void swap(vector<int> &nums, int idx1, int idx2) {
        int len = nums.size();
        if (idx1 >= 0 && idx1 < len && idx2 >= 0 && idx2 < len) {
            int temp = nums[idx1];
            nums[idx1] = nums[idx2];
            nums[idx2] = temp;
        }
    }
};

// 参考（非常推荐）：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/

// 相对于Soln_1，这个解法代码更简洁，思路更清晰
