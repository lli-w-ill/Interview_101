#include <vector>

using std::vector;
using std::swap;

class Solution_8 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;    // 采用「左闭右闭」原则
        int target = nums.size() - k;   // 第 k 大 等价于 第 size-k 小
        int mid;

        while (left < right) {
            mid = quickSelection(nums, left, right);

            if (mid == target) {
                return nums[mid];
            } else if (mid < target) {
                // 第 target 小在 mid 的右边
                left = mid + 1;
            } else if (mid > target) {
                // 第 target 小在 mid 的左边
                right = mid - 1;
            }
        }

        return nums[left];
    }

private:
    // 将 nums[left] 放在有序数组中应该在的位置
    // 并返回其所在位置的下标
    // 这里依然采取「左闭右闭」原则 --- nums[left ... right]
    int quickSelection(vector<int> &nums, int left, int right) {
        int i = left + 1;
        int j = right;

        while (true) {
            // 从前往后，找到第一个大于 nums[left] 的值
            while (i < right && nums[i] <= nums[left]) {
                i ++;
            }
            // 从后往前，找到第一个小于 nums[left] 的值
            while (j > left && nums[j] >= nums[left]) {
                j --;
            }
            if (i >= j) {
                break;
            }
            
            // 交换第一个大于 nums[left] 的值 和 最后一个小于 nums[left] 的值
            swap(nums[i], nums[j]);
        }
        
        // 将 nums[left] 放在正确的位置上，并返回
        swap(nums[left], nums[j]);

        return j;
    }

};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
