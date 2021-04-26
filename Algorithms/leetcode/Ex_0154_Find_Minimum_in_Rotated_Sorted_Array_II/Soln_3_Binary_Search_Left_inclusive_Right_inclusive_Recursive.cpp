#include <vector>

using std::vector;

class Solution_3 {
public:
    int findMin(vector<int>& nums) {
        return binarySearchFindMin(nums, 0, nums.size() - 1);   // 该解法采用「左闭右闭」原则
    }

private:
    int binarySearchFindMin(vector<int> &nums, int left, int right) {
        // 防止越界
        if (left < 0 || left >= nums.size() || right < 0 || right >= nums.size()) {
            return INT_MAX;
        }

        int min = nums[left];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            min = std::min(min, nums[mid]);

            if (nums[mid] == nums[left]) {
                // 无法判断当前旋转点在哪一边，对左右两部分分别用二分法求最小
                // 注1：这里提高了 Soln_2 中只右移一位 left 的效率，因为这里相当于分别对左右两边用二分法
                // 注2：但是仍然如果当 nums 中全部都是同一个数字时，相当于这个 if 条件会不断被递归执行，时间计算公式：T(N) = 2T(N/2) + O(1)，根据主定理，时间复杂度最坏情况下仍然是 O(N)
                int leftMin = binarySearchFindMin(nums, left, mid - 1);
                int rightMin = binarySearchFindMin(nums, mid + 1, right);
                return std::min(min, std::min(leftMin, rightMin));
            }

            if (nums[mid] <= nums[right]) {
                // nums[mid ... right] 是递增的，那么比 nums[mid] 更小的值一定在 nums[left ... mid-1]
                right = mid - 1;
            } else {
                // 旋转点在 nums[mid ... right] 中，那么比 nums[mid] 更小的值一定在 nums[mid+1 ... right]
                left = mid + 1;
            }
        }

        return min;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
